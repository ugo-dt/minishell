/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:18:29 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/01 15:51:33 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "shell.h"
#include "redirections.h"
#include "builtin.h"
#include <fcntl.h>

int	redirect_out(char *file, int append)
{
	if (append)
		g_sh.std_out = open(file, O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		g_sh.std_out = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (g_sh.std_out < 0)
	{
		ft_putstr_fd(SHELL_NAME, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		perror(file);
		return (0);
	}
	return (1);
}

int	redirect_in(char *file)
{
	g_sh.std_in = open(file, O_RDONLY, 0644);
	if (g_sh.std_in < 0)
	{
		ft_putstr_fd(SHELL_NAME, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		perror(file);
		return (0);
	}
	return (1);
}

void	close_builtin_redirections(t_cmd *cmd, size_t count)
{
	size_t	i;
	t_redir	*r;

	if (!cmd || !cmd->redir)
		return ;
	i = 0;
	r = cmd->redir;
	while (r && i < count)
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
	if (!heredoc_builtin(cmd, delim + quoted))
		return (0);
	close(cmd->fd_heredoc[1]);
	g_sh.std_in = cmd->fd_heredoc[0];
	return (1);
}

size_t	do_builtin_redirections(t_cmd *cmd)
{
	int		done;
	size_t	count;
	t_redir	*r;

	done = 1;
	count = -1;
	r = cmd->redir;
	while (r && done && count++)
	{
		if (r->mode == IO_FILE_IN)
			done = redirect_in(r->file);
		else if (r->mode == IO_FILE_OUT)
			done = redirect_out(r->file, 0);
		else if (r->mode == IO_FILE_APPEND)
			done = redirect_out(r->file, 1);
		else if (r->mode == IO_HEREDOC)
			done = start_heredoc(cmd, r->file);
		if (!done)
			return (-1);
		r = r->next;
	}
	return (count);
}
