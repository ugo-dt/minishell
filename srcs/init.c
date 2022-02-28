/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:05:33 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/28 21:32:35 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "error.h"
#include "env.h"
#include <errno.h>
#include <string.h>

/* TODO
PWD = getpwd
SHLVL = 1
_= minishell */
static void	no_envp(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		exit(set_errno(
				NULL, // name
				"error: could not get working directory", // error info
				errno, // errnum
				EXIT_FAILURE // exit value
				));
	g_sh.envp = new_envl("PWD", pwd, 1, NULL);
	free(pwd);
	envl_pushback(&g_sh.envp, parse_env_line_to_envl("SHLVL=1"));
	envl_pushback(&g_sh.envp, parse_env_line_to_envl("_=minishell"));
}

static void	increment_shlvl(void)
{
	int		nb;
	char	*inc;

	nb = ft_atoi(getenv("SHLVL"));
	if (nb < 0)
		nb = 0;
	inc = ft_itoa(nb + 1);
	if (!inc)
		return ;
	ft_setenv("SHLVL", inc, 1);
	free(inc);
}

void	init_env(const char **envp)
{
	size_t	i;

	if (!envp || !(*envp))
	{
		no_envp();
		return ;
	}
	i = 0;
	while (envp[i])
	{
		if (ft_strcmp(envp[i], "SHLVL") == 0
			&& ft_len_to_char(envp[i], '=') == 5)
			increment_shlvl();
		else
			envl_pushback(&g_sh.envp, parse_env_line_to_envl(envp[i]));
		i++;
	}
}
