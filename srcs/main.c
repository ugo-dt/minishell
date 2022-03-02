/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:41:32 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/02 16:13:32 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "init.h"
#include "libft.h"
#include "parser.h"
#include "prompt.h"
#include "shell.h"
#include "sig.h"

t_shell	g_sh;

static int	init_shell(const char **envp)
{
	g_sh.std_err = STDERR_FILENO;
	g_sh.std_in = STDIN_FILENO;
	g_sh.std_out = STDOUT_FILENO;
	init_signals();
	init_env(envp);
	g_sh.line = NULL;
	g_sh.error_message = 0;
	g_sh.exit_value = 0;
	g_sh.prompt = NULL;
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
		ft_dprintf(g_sh.std_err, "Aborting\n.");
		return (EXIT_FAILURE);
	}
	while (isatty(g_sh.std_in) && g_sh.status & FLAG_LOOP)
	{
		g_sh.status |= FLAG_INTERACTVE;
		g_sh.prompt = get_prompt();
		g_sh.line = readline(g_sh.prompt);
		g_sh.status &= ~FLAG_INTERACTVE;
		add_command_to_history();
		start_to_parse_command();
		if (g_sh.line)
			free(g_sh.line);
		g_sh.line = NULL;
	}
	return (exit_shell());
}
