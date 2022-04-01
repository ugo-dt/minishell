/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:18:24 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/04/01 19:50:26 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "env.h"
#include "heredoc.h"
#include "libft.h"
#include "errors.h"
#include "shell.h"
#include "pipe.h"
#include "sig.h"
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

static void	redirect_process(t_cmd *cmd, t_pipe *p, size_t i)
{
	if (cmd->next)
	{
		close(p->pipe[i][0]);
		if (dup2(p->pipe[i][1], STDOUT_FILENO) < 0)
			exit(set_errno("pipe error (output)",
					"dup2 error", errno, EXIT_FAILURE));
		close(p->pipe[i][1]);
	}
	if (i > 0)
	{
		close(p->pipe[i - 1][1]);
		if (dup2(p->pipe[i - 1][0], STDIN_FILENO) < 0)
			exit(set_errno("pipe error (input)",
					"dup2 error", errno, EXIT_FAILURE));
		close(p->pipe[i - 1][0]);
	}
}

static int	new_process(t_cmd *cmd, t_pipe *p, size_t i)
{
	pid_t	pid;

	if (cmd->next && (pipe(p->pipe[i]) < 0))
		exit(set_errno("pipeline", "pipe error", errno, EXIT_FAILURE));
	pid = fork();
	if (pid < 0)
		return (set_errno(NULL, "fork error", errno, -1));
	if (pid == 0)
	{
		redirect_process(cmd, p, i);
		if (!do_redirections(cmd, cmd->redir))
			return (-1);
		execute_process(cmd);
	}
	if (cmd->heredoc)
	{
		close(cmd->fd_heredoc[0]);
		close(cmd->fd_heredoc[1]);
	}
	if (i > 0)
	{
		close(p->pipe[i - 1][0]);
		close(p->pipe[i - 1][1]);
	}
	return (pid);
}

void	do_pipes(t_cmd *cmd, size_t pipes)
{
	size_t	i;
	int		j;
	t_pipe	p;
	t_cmd	*c;

	init_pipes(&p, pipes);
	i = 0;
	c = cmd;
	while (i < p.nb_cmd)
	{
		p.pid[i] = new_process(c, &p, i);
		if (p.pid[i] < 0)
			exit(EXIT_FAILURE);
		i++;
		c = c->next;
	}
	i = 0;
	j = 0;
	while (i < p.nb_cmd)
	{
		waitpid(p.pid[i], &p.exit_status, 0);
		if (WIFEXITED(p.exit_status))
			g_sh.exit_value = (t_uchar)WEXITSTATUS(p.exit_status);
		if (WIFSIGNALED(p.exit_status) || j)
		{
			print_signal((const char **)cmd->args, p.exit_status, !!cmd->next, p.pid[i]);
			j++;
		}
		cmd = cmd->next;
		i++;
	}
	free_pipe(p.pipe, p.nb_pipes);
	free(p.pid);
}

static void	start_with_heredocs(t_cmd *cmd)
{
	while (cmd)
	{
		if (!do_heredocs(cmd))
			exit(EXIT_FAILURE);
		cmd = cmd->next;
	}
}

void	execute_cmd(t_cmd *cmd)
{
	size_t	pipes;

	signal(SIGQUIT, SIG_DFL);
	start_with_heredocs(cmd);
	pipes = nb_pipes(cmd);
	if (pipes < 1)
	{
		if (!do_redirections(cmd, cmd->redir))
		{
			clear_cmd(cmd);
			exit(EXIT_FAILURE);
		}
		ft_setenv("_", cmd->args[cmd->nb_args - 1], 1);
		execute_process(cmd);
	}
	do_pipes(cmd, pipes);
	clear_cmd(cmd);
	exit_shell();
	exit(g_sh.exit_value);
}
