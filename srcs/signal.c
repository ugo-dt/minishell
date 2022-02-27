/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:08:24 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/27 21:22:51 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sig.h"
#include "termios.h"
#include "error.h"
#include "errno.h"

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

void reset_the_terminal(void)
{
	tcsetattr(0, 0, &g_sh.termios_save);
}

void	init_signals(void)
{
	int				rc;
	struct termios	termios_new;

	rc = tcgetattr(0, &g_sh.termios_save);
	if (rc)
		exit(set_error_message("tcgetattr", strerror(errno), EXIT_FAILURE));
	rc = atexit(reset_the_terminal);
	if (rc)
		exit(set_error_message("atexit", strerror(errno), EXIT_FAILURE));
	termios_new = g_sh.termios_save;
	termios_new.c_lflag &= ~ECHOCTL;
	rc = tcsetattr(0, 0, &termios_new);
	if (rc)
		exit(set_error_message("tcsetattr", strerror(errno), EXIT_FAILURE));
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}
