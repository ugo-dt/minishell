/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:18:19 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/28 21:01:26 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "shell.h"
#include "error.h"
#include <errno.h>

int	ft_setenv(const char *name, const char *value, int replace)
{
	t_envl	*new;
	t_envl	*lst;

	if (!name || !(*name) || ft_strchr(name, '='))
	{
		errno = EINVAL;
		return (-1);
	}
	new = new_envl(name, value, 1, NULL);
	if (!new)
		return (set_errno(NULL, NULL, ENOMEM, -1));
	if (!ft_getenv(name))
	{
		envl_pushback(&g_sh.envp, new_envl(name, value, 1, NULL));
		return (EXIT_SUCCESS);
	}
	if (replace)
	{
		ft_unsetenv(name);
		lst = g_sh.envp;
		envl_pushback(&g_sh.envp, new);
	}
	return (EXIT_SUCCESS);
}
