/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:41:32 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 17:10:19 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "sig.h"
# include <string.h>
# include "prompt.h"
# include "builtin.h"

static int	init_shell(const char **envp)
{
	(void)envp;
	init_signals();
	init_env(envp);
	g_sh.line = NULL;
	g_sh.error_message = NULL;
	g_sh.exit_value = 0;
	g_sh.status = FLAG_INTERACTVE | FLAG_LOOP;
	return (1);
}

static int	exit_shell(void)
{
	if (g_sh.prompt)
		free(g_sh.prompt);
	if (g_sh.error_message)
	{
		ft_putendl_fd(g_sh.error_message, STDERR_FILENO);
		free(g_sh.error_message);
	}
	if (g_sh.line)
		free(g_sh.line);
	clear_env_list(&g_sh.envp);
	return (g_sh.exit_value);
}

int	main(int ac, const char **av, const char **envp)
{
	(void)ac;
	(void)av;
	if (!init_shell(envp))
	{
		ft_dprintf(STDERR_FILENO, "Aborting\n.");
		return (EXIT_FAILURE);
	}
	while (isatty(STDIN_FILENO) && g_sh.status & FLAG_LOOP)
	{
		g_sh.prompt = get_prompt();
		g_sh.line = readline(g_sh.prompt);
		if (!g_sh.line || !strcmp(g_sh.line, "exit"))
			break ;
		if (!strcmp(g_sh.line, "env"))
			env();
		ft_printf("line: %s\n", g_sh.line);
		free(g_sh.line);
		g_sh.line = NULL;
	}
	ft_printf("exit\n");
	return (exit_shell());
}
