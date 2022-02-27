/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:05:33 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/26 16:22:08 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_envl	*parse_envp_to_envl(const char *line)
{
	size_t	i;
	char	*name;
	char	*value;
	t_envl	*envl;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '=')
		i++;
	name = ft_strndup(line, i + 1);
	name[i] = '\0';
	i++;
	value = ft_strdup(&line[i]);
	envl = new_envl(name, value, 1, NULL);
	free(name);
	free(value);
	return (envl);
}

/* TODO
PWD = getpwd
SHLVL = 1
_= minishell */
static void	no_envp(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	g_sh.envp = new_envl("PWD", pwd, 1, NULL);
	free(pwd);
	envl_pushback(&g_sh.envp, parse_envp_to_envl("SHLVL=1"));
	envl_pushback(&g_sh.envp, parse_envp_to_envl("_=minishell"));
}

void	init_env(const char **envp)
{
	unsigned int	i;

	if (!envp || !(*envp))
	{
		no_envp();
		return ;
	}
	i = 0;
	while (envp[i])
	{
		envl_pushback(&g_sh.envp, parse_envp_to_envl(envp[i]));
		i++;
	}
}
