/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:18:19 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 17:27:07 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "shell.h"
#include "err.h"
#include "errno.h"

int	ft_setenv(const char *name, const char *value, int replace)
{
	t_envl	*e;

	if (!name || !(*name) || ft_strchr(name, '=') || !value || !(*value))
		return (set_errno(EINVAL, -1));
	if (replace)
	{
		e = new_envl(name, value, 1, NULL);
		if (!e)
			return (set_errno(ENOMEM, EXIT_FAILURE));
		envl_pushback(&g_sh.envp, e);
	}
	return (EXIT_SUCCESS);
}
