/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:49:19 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/27 22:32:36 by ugdaniel         ###   ########.fr       */
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

static void	clear_cmd(t_cmd *cmd)
{
	if (cmd->next)
		clear_cmd(cmd->next);
	if (cmd->args)
		ft_free_array((void **)cmd->args);
	if (cmd->options)
		free(cmd->options);
	if (cmd->redir)
		free_redir(cmd->redir);
}

t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = ft_xmalloc(sizeof(t_cmd));
	ft_memset(cmd, 0, sizeof(t_cmd));
	return (cmd);
}

void	run_command(void)
{
	int		done;
	t_cmd	cmd;

	if (!g_sh.line || !ft_strcmp(g_sh.line, "exit"))
	{
		g_sh.status = g_sh.status & ~FLAG_LOOP;
		return ;
	}
	if (!should_run_command())
		return ;
	done = parse_command(&cmd, g_sh.line);
	if (done != 1)
		return ;
	if (ft_strcmp("env", g_sh.line) == 0)
		env();
#ifdef DEBUG
	t_redir	*r;
	t_cmd	*c;

	c = &cmd;
	while (c)
	{
		ft_printf("DEBUG: -------- COMMAND --------\n");
		ft_printf("DEBUG: command:\t%s\n", c->exec_name);
		for (size_t i = 1;i < c->nb_args; i++)
			ft_printf("DEBUG: Argument %d:\t%s\n", i, c->args[i]);

		for (r = c->redir;r;r = r->next)
			ft_printf("DEBUG: Redir %d:\t%s\n", r->mode, r->file);
		ft_printf("DEBUG: --------   END   --------\n");
		c = c->next;
	}
#endif
	clear_cmd(&cmd);
}
