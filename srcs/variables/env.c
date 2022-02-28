/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:55:16 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/28 20:16:18 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "error.h"
#include <errno.h>

t_envl	*new_envl(const char *name, const char *val, int export, t_envl *next)
{
	t_envl	*envl;

	envl = ft_xmalloc(sizeof(t_envl));
	envl->name = ft_strdup(name);
	if (!envl->name)
	{
		free(envl);
		return (set_errno_ptr(NULL, "error", ENOMEM, NULL));
	}
	envl->value = ft_strdup(val);
	if (!envl->value)
	{
		free(envl->name);
		free(envl);
		return (set_errno_ptr(NULL, "error", ENOMEM, NULL));
	}
	envl->export = export;
	envl->next = next;
	return (envl);
}

t_envl	*parse_env_line_to_envl(const char *line)
{
	size_t	i;
	char	*name;
	char	*value;
	t_envl	*envl;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '=')
		i++;
	name = ft_strndup(line, i + 1);
	name[i] = '\0';
	i++;
	value = ft_strdup(&line[i]);
	envl = new_envl(name, value, 1, NULL);
	free(name);
	free(value);
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
