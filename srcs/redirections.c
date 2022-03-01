/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:18:37 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/01 23:11:12 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"
#include "heredoc.h"
#include "cmd.h"
#include "error.h"
#include "shell.h"
#include <fcntl.h>
#include <string.h>

static int	redirect_out(char *file, int append)
{
	int		fd;

	if (append)
		fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
	{
		ft_putstr_fd(SHELL_NAME, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		perror(file);
		return (0);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		ft_putstr_fd(SHELL_NAME, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		perror("dup2");
		return (0);
	}
	close(fd);
	return (1);
}

static int	redirect_in(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY, 0644);
	if (fd < 0)
	{
		ft_putstr_fd(SHELL_NAME, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		perror(file);
		return (0);
	}
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		ft_putstr_fd(SHELL_NAME, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		perror("dup2");
		return (0);
	}
	close(fd);
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
	if (!heredoc(cmd, delim + quoted))
		return (0);
	close(cmd->fd_heredoc[1]);
	if (dup2(cmd->fd_heredoc[0], STDIN_FILENO) < 0)
	{
		ft_putstr_fd(SHELL_NAME, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	return (1);
}

int	do_redirections(t_cmd *cmd)
{
	int		done;
	t_redir	*r;

	done = 1;
	r = cmd->redir;
	while (r && done)
	{
		if (r->mode == IO_FILE_IN)
			done = redirect_in(r->file);
		else if (r->mode == IO_FILE_OUT)
			done = redirect_out(r->file, 0);
		else if (r->mode == IO_FILE_APPEND)
			done = redirect_out(r->file, 1);
		else if (r->mode == IO_HEREDOC)
			start_heredoc(cmd, r->file);
		r = r->next;
	}
	return (done);
}
