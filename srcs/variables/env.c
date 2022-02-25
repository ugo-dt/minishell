/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:55:16 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 16:15:18 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_envl	*new_envl(char *name, char *value, int export, t_envl *next)
{
	t_envl	*envl;

	envl = ft_xmalloc(sizeof(t_envl));
	if (name)
	{
		envl->name = ft_strdup(name);
		if (!envl->name)
			return (NULL);
	}
	if (value)
	{
		envl->value = ft_strdup(value);
		if (!envl->value)
			return (NULL);
	}
	envl->export = export;
	envl->next = next;
	return (envl);
}

void	envl_delone(t_envl *envl)
{
	if (!envl)
		return ;
	if (envl->name)
		free(envl->name);
	if (envl->value)
		free(envl->value);
	free(envl);
}

void	clear_env_list(t_envl **start)
{
	t_envl	*temp;

	if (!start || !(*start))
		return ;
	temp = *start;
	while (*start)
	{
		temp = *start;
		*start = (*start)->next;
		envl_delone(temp);
	}
}

void	envl_pushback(t_envl **lst, t_envl *new)
{
	t_envl	*temp;

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
