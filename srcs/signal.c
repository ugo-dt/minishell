/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:08:24 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 15:58:31 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sig.h"

void	sig_handler(int signum)
{
	g_sh.exit_value = 128 + signum;
	if (signum == SIGINT)
	{
		if (g_sh.status & FLAG_INTERACTVE)
		{
			ft_putchar('\n');
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			g_sh.prompt = get_prompt();
			if (g_sh.current_dir)
			free(g_sh.current_dir);
			g_sh.current_dir = NULL;
			ft_printf("\r%s", g_sh.prompt);
		}
	}
}

void	init_signals(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}
