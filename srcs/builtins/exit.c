/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:14:10 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/26 11:55:35 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "libft.h"
#include "errors.h"
#include "cmd.h"

static int	digits_only(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != '-' && s[i] != '+')
			return (0);
		i++;
	}
	return (i != 0);
}

static int	get_exit_code(t_cmd *cmd)
{
	size_t	i;

	i = 1;
	while (i < cmd->nb_args)
	{
		if (i > 1)
		{
			ft_dprintf(g_sh.std_err, "%s: %s: %s\n",
				SHELL_NAME, BUILTIN_EXIT_NAME, TOO_MANY_ARGS);
			return (EXIT_FAILURE);
		}
		if (digits_only(cmd->args[i]))
			g_sh.exit_value = ft_atoi(cmd->args[i]);
		else
		{
			ft_dprintf(g_sh.std_err, "%s: %s: %s: %s\n", SHELL_NAME,
				BUILTIN_EXIT_NAME, cmd->args[i], EXIT_NUM_ARG_REQUIRED);
			g_sh.status &= ~FLAG_LOOP;
			return (EXIT_MISUSE);
		}
		i++;
	}
	g_sh.status &= ~FLAG_LOOP;
	return (g_sh.exit_value);
}

int	builtin_exit(t_cmd *cmd)
{
	if (!cmd->args)
	{
		g_sh.status &= ~FLAG_LOOP;
		return (g_sh.exit_value);
	}
	return (get_exit_code(cmd));
}
