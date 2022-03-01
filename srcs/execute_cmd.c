/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:49:19 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/01 13:13:18 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "execute_cmd.h"
#include "shell.h"
#include "builtin.h"
#include "parser.h"
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
	s = g_sh.line;
	if (check_quotes(s) != 0)
		return (0);
	while (*s)
	{
		if (!ft_isspace(*s))
			return (1);
		s++;
	}
	return (0);
}

static void	execute_process(t_cmd *cmd)
{
	int		status;

	(void)cmd;
	printf("TODO: new process here\n");
	signal(SIGQUIT, SIG_DFL);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
		exit(EXIT_FAILURE);
	if (g_sh.exit_value != EXIT_SUCCESS)
		exit(EXIT_FAILURE);
	exit(0);
}

static void	execute_command(t_cmd *cmd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		return ;
	if (pid == 0)
		execute_process(cmd);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_sh.exit_value = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		g_sh.exit_value = 128 + WTERMSIG(status);
		if (WTERMSIG(status) == SIGINT)
			ft_putchar('\n');
		if (WTERMSIG(status) == SIGQUIT)
			ft_putendl_fd("Quit (core dumped)", STDERR_FILENO);
	}
}

void	run_command(void)
{
	t_cmd	cmd;

	ft_memset(&cmd, 0, sizeof(t_cmd));
	if (!should_run_command())
		return ;
	if (parse_command(&cmd, g_sh.line) != 1)
		return ;
	if (try_builtin_first(&cmd))
		return ;
	execute_command(&cmd);
	clear_cmd(&cmd);
}
