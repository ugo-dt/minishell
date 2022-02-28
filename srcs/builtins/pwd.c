/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:51:43 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/09/28 15:51:43 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "error.h"

int	pwd(t_cmd *cmd)
{
	char	*wd;

	if (cmd->nb_options && cmd->args && cmd->args[1])
	{
		if (cmd->args[1][1] == '-')
			return (unrecognized_option(BUILTIN_PWD, cmd->args[1], NULL));
		else
			return (show_error(BUILTIN_PWD, BAD_OPTION, cmd->args[1][1], NULL));
	}
	if (cmd->args && cmd->args[1])
		return (show_error(BUILTIN_PWD, TOO_MANY_ARGS, 0, NULL));
	wd = getcwd(NULL, 0);
	if (!wd)
		return (set_errno(BUILTIN_PWD, NULL, errno, EXIT_FAILURE));
	ft_putendl(wd);
	free(wd);
	return (EXIT_SUCCESS);
}
