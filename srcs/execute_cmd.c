/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:18:24 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/01 22:57:42 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "env.h"
#include "libft.h"
#include "error.h"
#include "shell.h"
#include "heredoc.h"
#include "pipe.h"

static void	redirect_process(t_cmd *cmd, t_pipe *p, size_t i)
{
	if (cmd->next)
	{
		close(p->pipe[i][0]);
		if (dup2(p->pipe[i][1], STDOUT_FILENO) < 0)
		{
			ft_putstr_fd(SHELL_NAME, STDERR_FILENO);
			ft_putstr_fd(": ", STDERR_FILENO);
			perror("dup21");
			exit(EXIT_FAILURE);
		}
		close(p->pipe[i][1]);
	}
	if (i > 0)
	{
		close(p->pipe[i - 1][1]);
		if (dup2(p->pipe[i - 1][0], STDIN_FILENO) < 0)
		{
			ft_putstr_fd(SHELL_NAME, STDERR_FILENO);
			ft_putstr_fd(": ", STDERR_FILENO);
			perror("dup22");
			exit(EXIT_FAILURE);
		}
		close(p->pipe[i - 1][0]);
	}
	close_pipes(p);
}

static int	new_process(t_cmd *cmd, t_pipe *p, size_t i, char **path)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_putstr_fd(SHELL_NAME, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		redirect_process(cmd, p, i);
		if (!do_redirections(cmd))
			exit(EXIT_FAILURE);
		find_file_in_path(cmd, path);
		execve(cmd->exec_name, cmd->args, path);
	}
	close(cmd->fd_heredoc[0]);
	close(cmd->fd_heredoc[1]);
	return (pid);
}

void	do_pipes(t_cmd *cmd, char **path, size_t pipes)
{
	size_t	i;
	size_t	j;
	t_pipe	p;

	init_pipes(&p, pipes);
	i = 0;
	j = 0;
	while (cmd)
	{
		p.pid[j] = new_process(cmd, &p, i, path);
		if (p.pid[j] < 0)
			exit(EXIT_FAILURE);
		i++;
		j++;
		cmd = cmd->next;
	}
	close_pipes(&p);
	i = 0;
	while (i < p.nb_cmd)
		waitpid(p.pid[i++], &p.exit_status, 0);
	if (WIFEXITED(p.exit_status))
		g_sh.exit_value = (t_uchar)WEXITSTATUS(p.exit_status);
	free_pipe(p.pipe, p.nb_pipes);
	free(p.pid);
}

void	execute_cmd(t_cmd *cmd)
{
	size_t	pipes;
	char	**path;

	path = ft_split(ft_getenv("PATH"), ':');
	pipes = nb_pipes(cmd);
	if (pipes < 1)
	{
		if (!do_redirections(cmd))
			exit(EXIT_FAILURE);
		find_file_in_path(cmd, path);
		execve(cmd->exec_name, cmd->args, path);
		set_error_message(cmd->exec_name, CMD_NOT_FOUND, 0);
		free(path);
		clear_cmd(cmd);
		exit(EXIT_NOT_FOUND);
	}
	do_pipes(cmd, path, pipes);
	free(path);
	clear_cmd(cmd);
	exit(g_sh.exit_value);
}
