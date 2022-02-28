/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:28:39 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/28 20:54:00 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "env.h"
#include "error.h"
#include "shell.h"

int	env(t_cmd *cmd)
{
	t_envl	*e;

	if (cmd->nb_options && cmd->args && cmd->args[1])
	{
		if (cmd->args[1][1] == '-')
			return (unrecognized_option(BUILTIN_ENV, cmd->args[1], NULL));
		else
			return (show_error(BUILTIN_ENV, BAD_OPTION, cmd->args[1][1], NULL));
	}
	if (cmd->args && cmd->args[1])
		return (show_error(BUILTIN_ENV, TOO_MANY_ARGS, 0, NULL));
	e = g_sh.envp;
	while (e)
	{
		ft_printf("%s=%s\n", e->name, e->value);
		e = e->next;
	}
	return (EXIT_SUCCESS);
}
