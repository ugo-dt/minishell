/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:18:24 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/01 21:25:08 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "env.h"
#include "libft.h"
#include "error.h"
#include "shell.h"
#include "heredoc.h"
#include "pipe.h"

void	do_pipes(t_cmd *cmd, char **path, size_t pipes)
{
	size_t	i;
	t_pipe	p;

	i = 0;
	(void)p;
#ifdef DEBUG
	t_redir	*r;
	t_cmd	*c;

	c = cmd;
	while (c)
	{
		ft_printf("DEBUG: -------- COMMAND --------\n");
		ft_printf("DEBUG: command:    %s\n", c->exec_name);
		for (size_t i = 1;i < c->nb_args; i++)
			ft_printf("DEBUG: argument %d: %s\n", i, c->args[i]);

		for (r = c->redir;r;r = r->next)
			ft_printf("DEBUG: redirect %d: %s\n", r->mode, r->file);
		ft_printf("DEBUG: --------   END   --------\n");
		c = c->next;
	}
#endif
	(void)path;
	(void)pipes;
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
		perror("execve");
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
