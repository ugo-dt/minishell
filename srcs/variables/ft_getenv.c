/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:14:19 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 17:29:11 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err.h"
#include "env.h"
#include "shell.h"

char	*ft_getenv(const char *name)
{
	t_envl	*e;

	if (!name)
		return (NULL);
	e = g_sh.envp;
	while (e)
	{
		if (e->name && (ft_strcmp(e->name, name)) == 0)
			return (e->value);
		e = e->next;
	}
	return (NULL);
}
