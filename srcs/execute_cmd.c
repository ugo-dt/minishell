/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:18:24 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/04 20:57:02 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "env.h"
#include "heredoc.h"
#include "libft.h"
#include "errors.h"
#include <errno.h>
#include "shell.h"
#include "heredoc.h"
#include "pipe.h"
#include <signal.h>
#include <sys/wait.h>

static void	redirect_process(t_cmd *cmd, t_pipe *p, size_t i)
{
	if (cmd->next)
	{
		close(p->pipe[i][0]);
		if (dup2(p->pipe[i][1], STDOUT_FILENO) < 0)
			exit(set_errno("could not redirect output",
					"dup2 error", errno, EXIT_FAILURE));
		close(p->pipe[i][1]);
	}
	if (i > 0)
	{
		close(p->pipe[i - 1][1]);
		if (dup2(p->pipe[i - 1][0], STDIN_FILENO) < 0)
			exit(set_errno("could not redirect input",
					"dup2 error", errno, EXIT_FAILURE));
		close(p->pipe[i - 1][0]);
	}
	close_pipes(p);
}

static int	new_process(t_cmd *cmd, t_pipe *p, size_t i)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (set_errno("could not create new process: ",
				"fork error", errno, -1));
	if (pid == 0)
	{
		redirect_process(cmd, p, i);
		if (!do_redirections(cmd, cmd->redir))
			return (-1);
		execute_process(cmd);
	}
	close(cmd->fd_heredoc[0]);
	close(cmd->fd_heredoc[1]);
	return (pid);
}

void	do_pipes(t_cmd *cmd, size_t pipes)
{
	size_t	i;
	t_pipe	p;

	init_pipes(&p, pipes);
	i = 0;
	while (i < p.nb_cmd)
	{
		p.pid[i] = new_process(cmd, &p, i);
		if (p.pid[i] < 0)
			exit(EXIT_FAILURE);
		i++;
		cmd = cmd->next;
	}
	close_pipes(&p);
	i = 0;
	while (i < p.nb_cmd)
		waitpid(p.pid[i++], &p.exit_status, 0);
	if (WIFEXITED(p.exit_status))
		g_sh.exit_value = (t_uchar)WEXITSTATUS(p.exit_status);
	if (WIFSIGNALED(p.exit_status))
		g_sh.exit_value = (t_uchar)WTERMSIG(p.exit_status);
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
