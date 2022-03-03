/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:44:11 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/03 15:12:08 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "heredoc.h"
#include "errors.h"
#include "redirections.h"
#include "shell.h"
#include "sig.h"
#include "parser.h"
#include <sys/wait.h>

static char	*get_line(char *line, char *delim)
{
	char	*dest;

	if (ft_strcmp(delim, line) == 0
		&& ft_strlen(delim) == ft_strlen(line))
		return (line);
	dest = expand_param(line, ft_strlen(line), TOKEN_WORD);
	free(line);
	return (dest);
}

static int	do_heredoc(t_cmd *cmd, char *delim)
{
	char	*line;

	signal(SIGINT, sig_execve_handler);
	close(cmd->fd_heredoc[0]);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		line = get_line(line, delim);
		if (!line)
			exit(set_errno("heredoc", "error", ENOMEM, EXIT_FAILURE));
		if (ft_strcmp(delim, line) == 0
			&& ft_strlen(delim) == ft_strlen(line))
			break ;
		ft_putendl_fd(line, cmd->fd_heredoc[1]);
		free(line);
		line = NULL;
	}
	close(cmd->fd_heredoc[1]);
	exit(EXIT_SUCCESS);
}

static int	heredoc_builtin(t_cmd *cmd, char *delim)
{
	pid_t	pid;
	int		status;

	if (pipe(cmd->fd_heredoc) < 0)
		return (set_errno("heredoc", "pipe error", errno, 0));
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid < 0)
		return (set_errno("heredoc", "fork error", errno, 0));
	if (pid == 0)
		do_heredoc(cmd, delim);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_sh.exit_value = WEXITSTATUS(status);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
		return (0);
	if (g_sh.exit_value != EXIT_SUCCESS)
		return (0);
	signal(SIGINT, sig_handler);
	return (1);
}

static int	start_heredoc(t_cmd *cmd, char *delim)
{
	int		quoted;

	quoted = 0;
	if (delim[quoted] == '\'' || delim[quoted] == '\"')
	{
		quoted = 1;
		delim[ft_strlen(delim) - 1] = '\0';
	}
	cmd->heredoc = 1;
	return (heredoc_builtin(cmd, delim + quoted));
}

int	do_heredocs_builtin(t_cmd *cmd)
{
	int		done;
	t_redir	*r;

	done = 1;
	r = cmd->redir;
	while (r && done)
	{
		if (r->mode == IO_HEREDOC)
			done = start_heredoc(cmd, r->file);
		if (!done)
			return (0);
		r = r->next;
	}
	return (done);
}
