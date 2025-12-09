/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:08:24 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/07/14 18:59:13 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sig.h"
#include "shell.h"
#include "termios.h"
#include "errors.h"
#include <errno.h>
#include <signal.h>
#include <unistd.h>

char	*ft_strsignal(int num)
{
	if (num == 0)
		return ("done");
	if (num == SIGQUIT)
		return ("quit");
	if (num == SIGABRT)
		return ("abort");
	if (num == SIGKILL)
		return ("kill");
	if (num == SIGBUS)
		return ("bus");
	if (num == SIGSEGV)
		return ("segmentation fault");
	if (num == SIGTERM)
		return ("terminated");
	return (NULL);
}

int	print_signal(int status, pid_t cpid)
{
	char	*sig;

	g_sh.exit_value = 128 + (t_uchar)WTERMSIG(status);
	if (WTERMSIG(status) == SIGINT)
	{
		ft_putstr_fd("^C\n", g_sh.std_err);
		return (0);
	}
	sig = ft_strsignal(WTERMSIG(status));
	if (!sig)
		return (0);
	ft_printf("\t%d %s  ", cpid, sig);
	return (ft_strlen(sig));
}

void	sig_execve_handler(int signum)
{
	g_sh.exit_value = 128 + signum;
	if (signum == SIGINT || signum == SIGQUIT)
	{
		ft_putchar_fd('\n', g_sh.std_out);
		exit(g_sh.exit_value);
	}
}

void	sig_handler(int signum)
{
	g_sh.exit_value = 128 + signum;
	if (g_sh.line)
		free(g_sh.line);
	g_sh.line = NULL;
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
