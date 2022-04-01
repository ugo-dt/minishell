/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:49:19 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/04/01 19:53:38 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "shell.h"
#include "builtin.h"
#include "sig.h"
#include "parser.h"
#include <signal.h>
#include <sys/wait.h>

static int	should_run_command(void)
{
	char	*s;

	if (!g_sh.line)
	{
		g_sh.status &= ~FLAG_LOOP;
		ft_putendl("exit");
		return (0);
	}
	if (check_quotes(g_sh.line) != 0)
	{
		g_sh.exit_value = 2;
		return (0);
	}
	s = g_sh.line;
	while (*s)
	{
		if (!ft_isspace(*s))
			return (1);
		s++;
	}
	return (0);
}

static void	start_new_process(t_cmd *cmd)
{
	pid_t	pid;
	int		status;

	if (nb_pipes(cmd))
		ft_setenv("_", "", 1);
	pid = fork();
	if (pid < 0)
		return ;
	if (pid == 0)
		execute_cmd(cmd);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_sh.exit_value = WEXITSTATUS(status);
	else if (WIFSIGNALED(status) && !nb_pipes(cmd))
		print_signal((const char **)cmd->args, status, 0, pid);
}

void	start_to_parse_command(void)
{
	t_cmd	cmd;

	ft_memset(&cmd, 0, sizeof(t_cmd));
	if (!should_run_command())
		return ;
	if (parse_command(&cmd, g_sh.line) != 1)
	{
		clear_cmd(&cmd);
		return ;
	}
	if (!nb_pipes(&cmd) && cmd.nb_args)
		ft_setenv("_", cmd.args[cmd.nb_args - 1], 1);
	if (!try_builtin_first(&cmd))
		start_new_process(&cmd);
	clear_cmd(&cmd);
}
