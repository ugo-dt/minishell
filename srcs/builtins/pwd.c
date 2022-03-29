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
#include "errors.h"

int	pwd(t_cmd *cmd)
{
	char	*wd;

	if (cmd->nb_options && cmd->args && cmd->args[1])
	{
		if (cmd->args[1][1] == '-')
			return (unrecognized_option(BUILTIN_PWD_NAME, cmd->args[1], NULL));
		else
			return (show_error(BUILTIN_PWD_NAME,
					BAD_OPTION, cmd->args[1][1], NULL));
	}
	if (cmd->args && cmd->args[1])
		return (show_error(BUILTIN_PWD_NAME, TOO_MANY_ARGS, 0, NULL));
	wd = getcwd(NULL, 0);
	if (!wd)
	{
		if (!g_sh.current_working_dir)
			return (set_errno(BUILTIN_PWD_NAME, NULL, errno, EXIT_FAILURE));
		ft_putendl_fd(g_sh.current_working_dir, g_sh.std_out);
		return (EXIT_SUCCESS);
	}
	ft_putendl_fd(wd, g_sh.std_out);
	free(wd);
	return (EXIT_SUCCESS);
}
