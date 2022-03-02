/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:45:58 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/02 13:44:24 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "errno.h"
#include "shell.h"

int	ft_unsetenv(const char *name)
{
	t_envl	*lst;
	t_envl	*prev;

	if (!name || !(*name) || ft_strchr(name, '='))
	{
		errno = EINVAL;
		return (-1);
	}
	lst = g_sh.envp;
	prev = NULL;
	while (lst)
	{
		if (ft_strcmp(lst->name, name) == 0
			&& ft_strlen(name) == ft_strlen(lst->name))
		{
			if (prev)
				prev->next = lst->next;
			envl_delone(lst);
			lst = prev->next;
			continue ;
		}
		prev = lst;
		lst = lst->next;
	}
	return (EXIT_SUCCESS);
}
