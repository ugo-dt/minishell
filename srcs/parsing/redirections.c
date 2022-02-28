/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:41:51 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/28 22:10:24 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "redirections.h"
#include <stdlib.h>

static int	get_redirection_type(unsigned int type)
{
	if (type == TOKEN_GREAT)
		return (IO_FILE_OUT);
	else if (type == TOKEN_LESS)
		return (IO_FILE_IN);
	else if (type == TOKEN_GREATGREAT)
		return (IO_FILE_APPEND);
	else if (type == TOKEN_LESSLESS)
		return (IO_HEREDOC);
	return (0);
}

t_redir	*new_redirection(const char *file, size_t size, unsigned int type)
{
	t_redir	*r;

	r = ft_xmalloc(sizeof(t_redir));
	if (file)
	{
		r->file = expand_param(file, size, type);
		if (!r->file)
		{
			free(r);
			return (NULL);
		}
	}
	else
		r->file = NULL;
	r->mode = get_redirection_type(type);
	r->next = NULL;
	return (r);
}

void	free_redir(t_redir *redir)
{
	if (redir->next)
		free_redir(redir->next);
	if (redir)
	{
		if (redir->file)
			free(redir->file);
		free(redir);
	}
}

void	ft_rediraddback(t_redir **lst, t_redir *new)
{
	t_redir	*temp;

	temp = *lst;
	if (temp == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}
