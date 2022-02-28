/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:43:11 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/28 21:32:49 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	show_error(char *name, char *error, char option, char *usage)
{
	ft_dprintf(STDERR_FILENO, "%s", SHELL_NAME);
	if (name && error)
	{
		if (option)
			ft_dprintf(STDERR_FILENO, ": %s: %s: -%c\n", name, error, option);
		else
			ft_dprintf(STDERR_FILENO, ": %s: %s\n", name, error);
	}
	if (usage)
		ft_dprintf(STDERR_FILENO, "%s\n", usage);
	return (EXIT_FAILURE);
}

int	unrecognized_option(char *name, char *option, char *usage)
{
	ft_dprintf(STDERR_FILENO, "%s", SHELL_NAME);
	if (name && option)
		ft_dprintf(
			STDERR_FILENO, ": %s: unrecognized option '%s'\n", name, option);
	if (usage)
		ft_dprintf(STDERR_FILENO, "%s\n", usage);
	return (EXIT_FAILURE);
}

int	find_builtin(t_cmd *cmd)
{
	int		done;

	if (!cmd || !cmd->exec_name)
		return (EXIT_SUCCESS);
	done = -1;
	if (ft_strcmp(cmd->exec_name, BUILTIN_ECHO) == 0)
		done = echo(cmd);
	else if (ft_strcmp(cmd->exec_name, BUILTIN_CD) == 0)
		done = cd(cmd);
	else if (ft_strcmp(cmd->exec_name, BUILTIN_PWD) == 0)
		done = pwd(cmd);
	else if (ft_strcmp(cmd->exec_name, BUILTIN_EXPORT) == 0)
		done = export(cmd);
	else if (ft_strcmp(cmd->exec_name, BUILTIN_UNSET) == 0)
		done = unset(cmd);
	else if (ft_strcmp(cmd->exec_name, BUILTIN_ENV) == 0)
		done = env(cmd);
	else if (ft_strcmp(cmd->exec_name, BUILTIN_HISTORY) == 0)
		done = print_history();
	else if (ft_strcmp(cmd->exec_name, BUILTIN_EXIT) == 0)
		done = run_exit(cmd);
	return (done);
}

int	try_builtin_first(t_cmd *cmd)
{
	int	done;

	if (nb_pipes(cmd) < 1)
	{
		done = find_builtin(cmd);
		if (done != -1)
		{
			g_sh.exit_value = (t_uchar)done;
			return (1);
		}
	}
	return (0);
}
