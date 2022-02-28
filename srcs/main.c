/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:41:32 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/28 13:14:30 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_cmd.h"
#include "sig.h"
#include "error.h"
#include "minishell.h"
#include "prompt.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

static int	init_shell(const char **envp)
{
	(void)envp;
	init_signals();
	init_env(envp);
	g_sh.line = NULL;
	g_sh.error_message = 0;
	g_sh.exit_value = 0;
	g_sh.status = FLAG_INTERACTVE | FLAG_LOOP;
	return (1);
}

static int	exit_shell(void)
{
	if (g_sh.prompt)
		free(g_sh.prompt);
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
		add_command_to_history();
		run_command();
		if (g_sh.line)
			free(g_sh.line);
		g_sh.line = NULL;
	}
	return (exit_shell());
}
