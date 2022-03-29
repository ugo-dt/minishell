/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:18:37 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/29 13:53:49 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"
#include "heredoc.h"
#include "cmd.h"
#include "errors.h"
#include "shell.h"
#include "parser.h"
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
		return (set_errno(file, NULL, errno, 0));
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (set_errno("redirection error", "dup2", errno, 0));
	close(fd);
	return (1);
}

static int	redirect_in(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY, 0644);
	if (fd < 0)
		return (set_errno(file, NULL, errno, 0));
	if (dup2(fd, STDIN_FILENO) < 0)
		return (set_errno("redirection error", "dup2", errno, 0));
	close(fd);
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
	cmd->redir->file  = remove_quotes(delim);
	cmd->heredoc = 1;
	return (heredoc(cmd, cmd->redir->file, quoted));
}

int	do_heredocs(t_cmd *cmd)
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

int	do_redirections(t_cmd *cmd, t_redir *r)
{
	int		done;

	done = 1;
	while (r && done)
	{
		if (r->mode == IO_FILE_IN)
			done = redirect_in(r->file);
		else if (r->mode == IO_FILE_OUT)
			done = redirect_out(r->file, 0);
		else if (r->mode == IO_FILE_APPEND)
			done = redirect_out(r->file, 1);
		else if (r->mode == IO_HEREDOC)
		{
			close(cmd->fd_heredoc[1]);
			if (dup2(cmd->fd_heredoc[0], STDIN_FILENO) < 0)
				exit(set_errno("dup2", NULL, errno, EXIT_FAILURE));
		}	
		if (!done)
			return (0);
		r = r->next;
	}
	return (done);
}
