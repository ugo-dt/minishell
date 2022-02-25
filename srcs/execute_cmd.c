/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:49:19 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 22:15:06 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_cmd.h"
#include "shell.h"
#include "builtin.h"
#include "parser.h"

static int	should_run_command(void)
{
	char	*s;

	s = g_sh.line;
	while (*s)
	{
		if (!ft_isspace(*s))
			return (1);
		s++;
	}
	return (0);
}

void	run_command(void)
{
	int		done;
	t_cmd	cmd;

	if (!should_run_command())
		return ;
	done = parse_command(&cmd);
	if (done != 1)
		return ;
	if (ft_strcmp("env", g_sh.line) == 0)
		env();
}
