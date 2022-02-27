/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:18:19 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/27 20:42:30 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "shell.h"
#include "error.h"

int	ft_setenv(const char *name, const char *value, int replace)
{
	t_envl	*e;

	if (!name || !(*name) || ft_strchr(name, '=') || !value || !(*value))
	{
		errno = EINVAL;
		return (-1);
	}
	if (replace)
	{
		e = new_envl(name, value, 1, NULL);
		if (!e)
			return (set_errno(NULL, NULL, ENOMEM, -1));
		envl_pushback(&g_sh.envp, e);
	}
	return (EXIT_SUCCESS);
}
