/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:08:24 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/27 10:15:27 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sig.h"

void	sig_execve_handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar('\n');
		signal(SIGINT, (void *)sig_handler);
		exit(g_sh.exit_value);
	}
	else if (signum == SIGQUIT)
		g_sh.exit_value = 128 + signum;
}

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
		}
	}
}

void	init_signals(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}
