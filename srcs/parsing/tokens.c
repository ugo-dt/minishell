/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 11:08:01 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/27 14:16:57 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token	*new_token(TOKEN type, const char *word, size_t wsize)
{
	t_token	*t;

	t = ft_xmalloc(sizeof(t_token));
	t->type = type;
	t->word = (char *)word;
	t->wsize = wsize;
	t->next = NULL;
	return (t);
}

size_t	size_tokenlist(t_token *lst)
{
	size_t	size;
	t_token	*temp;

	size = 0;
	temp = lst;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

void	clear_tokenlist(t_token **t)
{
	t_token	*temp;

	if (!t || !(*t))
		return ;
	temp = *t;
	while (*t)
	{
		temp = *t;
		*t = (*t)->next;
		free(temp);
	}
}

void	tokenlist_add_back(t_token **lst, t_token *new)
{
	t_token	*temp;

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

void	change_last_token_type(t_token **lst, TOKEN type)
{
	t_token	*temp;

	temp = *lst;
	if (temp == NULL)
		return ;
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->type = type;
}
