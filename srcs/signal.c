/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:08:24 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/03 12:07:42 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sig.h"
#include "shell.h"
#include "termios.h"
#include "error.h"
#include <errno.h>

void	sig_execve_handler(int signum)
{
	g_sh.exit_value = 128 + signum;
	if (signum == SIGINT)
	{
		ft_putchar_fd('\n', g_sh.std_out);
		exit(g_sh.exit_value);
	}
}

void	sig_handler(int signum)
{
	g_sh.exit_value = EXIT_FAILURE;
	if (signum == SIGINT)
	{
		if (g_sh.status & FLAG_INTERACTVE)
		{
			ft_putchar_fd('\n', g_sh.std_out);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
}

void	init_signals(void)
{
	int				rc;
	struct termios	termios_new;

	rc = tcgetattr(g_sh.std_in, &g_sh.termios_save);
	if (rc)
		exit(set_error_message("tcgetattr", strerror(errno), EXIT_FAILURE));
	termios_new = g_sh.termios_save;
	termios_new.c_lflag &= ~ECHOCTL;
	rc = tcsetattr(0, 0, &termios_new);
	if (rc)
		exit(set_error_message("tcsetattr", strerror(errno), EXIT_FAILURE));
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}
