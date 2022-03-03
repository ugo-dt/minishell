/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:43:11 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/03 15:28:13 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "shell.h"

int	show_error(char *name, char *error, char option, char *usage)
{
	ft_dprintf(g_sh.std_err, "%s", SHELL_NAME);
	if (name && error)
	{
		if (option)
			ft_dprintf(g_sh.std_err, ": %s: %s: -%c\n", name, error, option);
		else
			ft_dprintf(g_sh.std_err, ": %s: %s\n", name, error);
	}
	if (usage)
		ft_dprintf(g_sh.std_err, "%s\n", usage);
	return (EXIT_FAILURE);
}

int	unrecognized_option(char *name, char *option, char *usage)
{
	ft_dprintf(g_sh.std_err, "%s", SHELL_NAME);
	if (name && option)
		ft_dprintf(
			g_sh.std_err, ": %s: unrecognized option '%s'\n", name, option);
	if (usage)
		ft_dprintf(g_sh.std_err, "%s\n", usage);
	return (EXIT_FAILURE);
}

int	find_builtin(t_cmd *cmd)
{
	if (!cmd || !cmd->exec_name)
		return (EXIT_SUCCESS);
	if (ft_strcmp(cmd->exec_name, BUILTIN_ECHO_NAME) == 0)
		return (BUILTIN_ECHO);
	else if (ft_strcmp(cmd->exec_name, BUILTIN_CD_NAME) == 0)
		return (BUILTIN_CD);
	else if (ft_strcmp(cmd->exec_name, BUILTIN_PWD_NAME) == 0)
		return (BUILTIN_PWD);
	else if (ft_strcmp(cmd->exec_name, BUILTIN_EXPORT_NAME) == 0)
		return (BUILTIN_EXPORT);
	else if (ft_strcmp(cmd->exec_name, BUILTIN_UNSET_NAME) == 0)
		return (BUILTIN_UNSET);
	else if (ft_strcmp(cmd->exec_name, BUILTIN_ENV_NAME) == 0)
		return (BUILTIN_ENV);
	else if (ft_strcmp(cmd->exec_name, BUILTIN_HISTORY_NAME) == 0)
		return (BUILTIN_HISTORY);
	else if (ft_strcmp(cmd->exec_name, BUILTIN_EXIT_NAME) == 0)
		return (BUILTIN_EXIT);
	return (EXIT_NOT_FOUND);
}

int	run_builtin(t_cmd *cmd, int builtin)
{
	if (builtin == BUILTIN_ECHO)
		return (echo(cmd));
	if (builtin == BUILTIN_CD)
		return (cd(cmd));
	if (builtin == BUILTIN_PWD)
		return (pwd(cmd));
	if (builtin == BUILTIN_EXPORT)
		return (export(cmd));
	if (builtin == BUILTIN_UNSET)
		return (unset(cmd));
	if (builtin == BUILTIN_ENV)
		return (env(cmd));
	if (builtin == BUILTIN_HISTORY)
		return (print_history());
	if (builtin == BUILTIN_EXIT)
		return (run_exit(cmd));
	return (EXIT_FAILURE);
}

int	try_builtin_first(t_cmd *cmd)
{
	int		builtin;
	long	redir;

	if (nb_pipes(cmd) < 1)
	{
		if (cmd->nb_args)
			ft_setenv("_", cmd->args[cmd->nb_args - 1], 1);
		builtin = find_builtin(cmd);
		if (builtin == EXIT_NOT_FOUND)
			return (0);
		redir = 0;
		if (nb_redir(cmd) > 0)
		{
			redir = do_builtin_redirections(cmd, cmd->redir);
			if (redir < 0)
			{
				g_sh.exit_value = EXIT_FAILURE;
				return (2);
			}
		}
		if (builtin == BUILTIN_EXIT)
			ft_putendl("exit");
		g_sh.exit_value = (t_uchar)run_builtin(cmd, builtin);
		close_builtin_redirections(cmd, redir);
		return (1);
	}
	return (0);
}
