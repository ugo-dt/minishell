/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:28:39 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 17:16:49 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "env.h"
#include "shell.h"

int	env(void)
{
	t_envl	*e;
	t_envl	*temp;

	e = g_sh.envp;
	temp = NULL;
	while (e)
	{
		if (e->value && ft_strcmp(e->value, "_") == 0)
			temp = e;
		else if (e->name && e->value)
			ft_printf("%s=%s\n", e->name, e->value);
		e = e->next;
	}
	if (temp && temp->name && temp->value)
		ft_printf("%s=%s\n", temp->name = temp->value);
	return (EXIT_SUCCESS);
}