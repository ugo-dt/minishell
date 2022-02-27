/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:41:51 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/27 15:34:57 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "redirections.h"
#include <stdlib.h>

t_redir	*new_redirection(char *file, size_t size, unsigned int type)
{
	t_redir	*r;

	r = ft_xmalloc(sizeof(t_redir));
	if (file)
	{
		r->file = ft_strndup(file, size + 1);
		if (!r->file)
		{
			free(r);
			return (NULL);
		}
	}
	else
		r->file = NULL;
	if (type == TOKEN_GREAT)
		r->mode = IO_FILE_OUT;
	else if (type == TOKEN_LESS)
		r->mode = IO_FILE_IN;
	else if (type == TOKEN_GREATGREAT)
		r->mode = IO_FILE_APPEND;
	else if (type == TOKEN_LESSLESS)
		r->mode = IO_HEREDOC;
	else
		r->mode = 0;
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