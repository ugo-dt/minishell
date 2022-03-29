/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:44:26 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/17 22:59:24 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "errors.h"
#include <string.h>

static char	*do_trim(char **comp, char *newpath)
{
	unsigned int	i;
	char			*temp;

	i = 0;
	while (comp[i])
	{
		if (can_copy(comp, &i))
		{
			if (newpath)
			{
				temp = newpath;
				newpath = ft_strjoin_3(newpath, comp[i], "/");
				free(temp);
			}
			else
				newpath = ft_strjoin(comp[i], "/");
		}
		i++;
	}
	return (newpath);
}

static char	*trim_path(char *path)
{
	char		*newpath;
	char		**comp;

	newpath = NULL;
	comp = ft_split(path, '/');
	if (!comp)
		return (NULL);
	if (path[0] == '/')
		newpath = ft_strdup("/");
	newpath = do_trim(comp, newpath);
	free(path);
	ft_free_array((void **)comp);
	return (newpath);
}

static char	*get_pathname(t_cmd *cmd, char *pwd)
{
	char	*path;
	char	*oldpwd;

	if (cmd->args[1][0] == '/')
		path = ft_strdup(cmd->args[1]);
	else if ((!ft_strcmp(cmd->args[1], ".") && ft_strlen(cmd->args[1]) == 1)
		|| (!ft_strcmp(cmd->args[1], "..") && ft_strlen(cmd->args[1]) == 2))
		path = ft_strjoin_3(pwd, "/", cmd->args[1]);
	else if (!ft_strcmp(cmd->args[1], "-") && ft_strlen(cmd->args[1]) == 1)
	{
		oldpwd = ft_getenv("OLDPWD");
		if (!oldpwd || ft_strlen(oldpwd) < 1)
		{
			show_error(BUILTIN_CD_NAME, OLDPWD_NOT_SET, 0, NULL);
			return (NULL);
		}
		path = ft_strdup(oldpwd);
	}
	else
		path = ft_strdup(cmd->args[1]);
	if (path)
		return (trim_path(path));
	return (NULL);
}

int	cd_path(char *path, char *pwd, char *original)
{
	int		done;
	char	*cwd;

	done = chdir(path);
	if (g_sh.current_working_dir)
		free(g_sh.current_working_dir);
	g_sh.current_working_dir = getcwd(NULL, 0);
	free(path);
	if (done != EXIT_SUCCESS && original)
	{
		ft_dprintf(g_sh.std_err, "%s: %s: %s: %s\n",
			SHELL_NAME, BUILTIN_CD_NAME, original, strerror(errno));
		return (EXIT_FAILURE);
	}
	if (!pwd)
		ft_unsetenv("OLDPWD");
	else
		ft_setenv("OLDPWD", pwd, 1);
	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		ft_setenv("PWD", cwd, 1);
		free(cwd);
	}
	return (EXIT_SUCCESS);
}

int	cd(t_cmd *cmd)
{
	char	*pwd;
	char	*home;
	char	*path;

	pwd = ft_getenv("PWD");
	if (!cmd->args[1])
	{
		home = ft_getenv("HOME");
		if (!home || ft_strlen(home) < 1)
			return (show_error(BUILTIN_CD_NAME, HOME_NOT_SET, 0, NULL));
		path = ft_strdup(home);
	}
	else
		path = get_pathname(cmd, pwd);
	if (!path)
		return (EXIT_SUCCESS);
	if (cmd->args && cmd->args[1])
		return (cd_path(path, pwd, cmd->args[1]));
	return (cd_path(path, pwd, NULL));
}
