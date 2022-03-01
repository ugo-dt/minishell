/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:55:40 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/01 21:13:19 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "parser.h"
#include "sig.h"
#include "libft.h"
#include "error.h"
#include "errno.h"

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
		{
			ft_dprintf(g_sh.std_err, "%s: unexpected error\n", SHELL_NAME);
			exit(EXIT_FAILURE);
		}
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

int	heredoc(t_cmd *cmd, char *delim)
{
	pid_t	pid;
	int		status;

	if (pipe(cmd->fd_heredoc) < 0)
		exit(set_errno("heredoc", "pipe", errno, 0));
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid < 0)
	{
		ft_putstr_fd(SHELL_NAME, g_sh.std_err);
		ft_putstr_fd(": ", g_sh.std_err);
		perror("heredoc");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		do_heredoc(cmd, delim);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_sh.exit_value = WEXITSTATUS(status);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
		return (0);
	if (g_sh.exit_value != EXIT_SUCCESS)
		return (0);
	return (1);
}
