/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:18:29 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/04 20:52:22 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "errors.h"
#include "heredoc.h"
#include <errno.h>
#include "shell.h"
#include "redirections.h"
#include "builtin.h"
#include <fcntl.h>

static long	redirect_out(char *file, int append)
{
	if (append)
		g_sh.std_out = open(file, O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		g_sh.std_out = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (g_sh.std_out < 0)
	{
		g_sh.std_out = STDOUT_FILENO;
		g_sh.exit_value = EXIT_FAILURE;
		return (set_errno(file, NULL, errno, 0));
	}
	return (1);
}

static long	redirect_in(char *file)
{
	g_sh.std_in = open(file, O_RDONLY, 0644);
	if (g_sh.std_in < 0)
	{
		g_sh.std_in = STDIN_FILENO;
		g_sh.exit_value = EXIT_FAILURE;
		return (set_errno(file, NULL, errno, 0));
	}
	return (1);
}

int	close_builtin_redirections(t_cmd *cmd, size_t redirs)
{
	size_t	i;
	t_redir	*r;

	if (!cmd || !cmd->redir)
		return (0);
	i = 0;
	r = cmd->redir;
	while (r && i < redirs)
	{
		if (r->mode == IO_FILE_IN)
			close(g_sh.std_in);
		else if (r->mode == IO_FILE_OUT || r->mode == IO_FILE_APPEND)
			close(g_sh.std_out);
		else if (r->mode == IO_HEREDOC)
			close(cmd->fd_heredoc[0]);
		r = r->next;
		i++;
	}
	g_sh.std_in = STDIN_FILENO;
	g_sh.std_out = STDOUT_FILENO;
	g_sh.std_err = STDERR_FILENO;
	return (0);
}

int	do_builtin_redirections(t_cmd *cmd, t_redir *r)
{
	int		count;
	int		done;

	done = 1;
	count = 0;
	while (r)
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
			g_sh.std_in = cmd->fd_heredoc[0];
		}
		if (!done++)
			return (close_builtin_redirections(cmd, count));
		count++;
		r = r->next;
	}
	return (1);
}
