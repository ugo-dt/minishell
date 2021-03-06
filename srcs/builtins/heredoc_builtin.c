/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:44:11 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/18 21:26:30 by ugdaniel         ###   ########.fr       */
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

static char	*get_line(char *line, char *delim, int quoted)
{
	char	*dest;

	if ((ft_strcmp(delim, line) == 0
			&& ft_strlen(delim) == ft_strlen(line)) || quoted)
		return (line);
	dest = expand(&line, 0, 0, NULL);
	return (dest);
}

static int	do_heredoc(t_cmd *cmd, char *delim, int quoted)
{
	char	*line;

	signal(SIGINT, sig_execve_handler);
	close(cmd->fd_heredoc[0]);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		line = get_line(line, delim, quoted);
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

static int	heredoc_builtin(t_cmd *cmd, char *delim, int quoted)
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
		do_heredoc(cmd, delim, quoted);
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
	int		i;
	int		quoted;

	i = 0;
	quoted = 0;
	while (delim[i])
	{
		if (delim[i] == '\'' || delim[i] == '\'')
		{
			quoted = 1;
			break ;
		}
		i++;
	}
	delim = remove_quotes(ft_strdup(delim));
	cmd->heredoc = 1;
	return (heredoc_builtin(cmd, delim, quoted));
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
		{
			g_sh.exit_value = EXIT_FAILURE;
			return (0);
		}
		r = r->next;
	}
	return (done);
}
