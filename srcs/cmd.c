/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:37:11 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/28 17:26:19 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "libft.h"

size_t	nb_pipes(t_cmd *cmd)
{
	t_cmd	*c;
	size_t	nb_pipes;

	if (!cmd)
		return (0);
	c = cmd;
	nb_pipes = 0;
	while (c->next)
	{
		c = c->next;
		nb_pipes++;
	}
	return (nb_pipes);
}

size_t	nb_redir(t_cmd *cmd)
{
	t_cmd	*c;
	size_t	nb_redir;

	if (!cmd->redir)
		return (0);
	c = cmd;
	nb_redir = 1;
	while (c)
	{
		if (c->redir)
			nb_redir++;
		c = c->next;
	}
	return (nb_redir);
}

void	clear_cmd(t_cmd *cmd)
{
	if (cmd->next)
		clear_cmd(cmd->next);
	if (cmd->args)
		ft_free_array((void **)cmd->args);
	if (cmd->redir)
		free_redir(cmd->redir);
}

t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = ft_xmalloc(sizeof(t_cmd));
	ft_memset(cmd, 0, sizeof(t_cmd));
	return (cmd);
}
