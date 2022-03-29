/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:04:47 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/29 12:14:41 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "builtin.h"
#include "errors.h"
#include "shell.h"
#include "libft.h"
#include "xmalloc.h"
#include <sys/stat.h>

static void	find_file_in_path(t_cmd *cmd, char **path)
{
	int			i;
	char		*temp;
	char		*dst;
	struct stat	buffer;

	if (!path || !(*path) || !cmd || !cmd->exec_name
		|| ft_strchr(cmd->exec_name, '/'))
		return ;
	temp = ft_strjoin("/", cmd->exec_name);
	i = 0;
	while (path[i] && temp)
	{
		dst = ft_strjoin(path[i], temp);
		if ((stat(dst, &buffer) == 0))
		{
			cmd->exec_name = dst;
			break ;
		}
		free(dst);
		i++;
	}
	free(temp);
}

static char	**envp_to_array(void)
{
	char	**envp;
	t_envl	*envl;
	size_t	i;

	envl = g_sh.envp;
	i = 0;
	while (envl)
	{
		i++;
		envl = envl->next;
	}
	envp = ft_xmalloc(sizeof(char *) * (i + 1));
	envl = g_sh.envp;
	i = 0;
	while (envl)
	{
		if (envl->export)
			envp[i++] = ft_strjoin_3(envl->name, "=", envl->value);
		envl = envl->next;
	}
	envp[i] = NULL;
	return (envp);
}

void	execute_process(t_cmd *cmd)
{
	int		done;
	char	**path;

	done = find_builtin(cmd);
	if (done != EXIT_NOT_FOUND)
		exit(run_builtin(cmd, done));
	path = ft_split(ft_getenv("PATH"), ':');
	find_file_in_path(cmd, path);
	execve(cmd->exec_name, cmd->args, envp_to_array());
	set_error_message(cmd->args[0], CMD_NOT_FOUND, 0);
	ft_free_array((void **)path);
	clear_cmd(cmd);
	exit_shell();
	exit(EXIT_NOT_FOUND);
}
