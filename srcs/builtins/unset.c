/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:29:58 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/28 21:36:09 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "error.h"
#include "cmd.h"

int	unset(t_cmd *cmd)
{
	size_t	i;
	int		done;

	if (cmd->nb_options)
		return (show_error(BUILTIN_UNSET, BAD_OPTION,
				cmd->args[1][1], EXPORT_USAGE));
	if (cmd->args && !cmd->args[1])
		return (EXIT_SUCCESS);
	i = 1;
	done = 0;
	while (i < cmd->nb_args)
	{
		if (ft_strchr(cmd->args[i], '=') || ft_strchr(cmd->args[i], '?'))
			ft_dprintf(STDERR_FILENO, "%s: %s: '%s': %s\n", SHELL_NAME,
				BUILTIN_UNSET, cmd->args[i], INVALID_IDENTIFIER);
		else
			done -= ft_unsetenv(cmd->args[i]);
		i++;
	}
	return (!(done == 0));
}
