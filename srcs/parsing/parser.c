/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:32:03 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/30 18:07:33 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "shell.h"

static int	get_arguments(t_cmd *cmd, t_token **list)
{
	size_t	i;
	t_token	*temp;
	t_token	*prev;

	cmd->args = malloc(sizeof(char *) * (cmd->nb_args + 1));
	cmd->args[cmd->nb_args] = NULL;
	temp = *list;
	prev = NULL;
	i = 0;
	while (temp && i < cmd->nb_args)
	{
		if (temp->type == TOKEN_PIPE)
			break ;
		if (!prev && temp->type == TOKEN_WORD)
			cmd->args[i++] = expand_param(temp->word, temp->wsize, 0);
		else if (prev && prev->type == TOKEN_WORD && temp->type == TOKEN_WORD)
			cmd->args[i++] = expand_param(temp->word, temp->wsize, prev->type);
		prev = temp;
		temp = temp->next;
	}
	if (cmd->args)
		cmd->exec_name = cmd->args[0];
	return (1);
}

static void	parse_tokens(t_token *temp, t_token *prev, t_cmd *c)
{
	while (temp)
	{
		if (temp->type == TOKEN_PIPE)
		{
			c->next = new_cmd();
			parse_tokens(temp->next, NULL, c->next);
			get_arguments(c->next, &temp->next);
			break ;
		}
		if ((!prev && temp->type == TOKEN_WORD)
			|| (prev && prev->type == TOKEN_WORD && temp->type == TOKEN_WORD))
			c->nb_args++;
		if (temp->type >= TOKEN_GREAT && temp->type <= TOKEN_LESSLESS)
		{
			prev = temp;
			temp = temp->next;
			if (temp)
				ft_rediraddback(&c->redir,
					new_redirection(temp->word, temp->wsize, prev->type));
		}
		prev = temp;
		temp = temp->next;
	}
}

int	parse_command(t_cmd *cmd, const char *line)
{
	t_token	*tokenlist;

	if (!line || !cmd)
		return (0);
	tokenlist = lexer(line, 0);
	if (!tokenlist)
		return (0);
	if (check_token_order(&tokenlist) != 0)
	{
		clear_tokenlist(&tokenlist);
		return (0);
	}
	parse_tokens(tokenlist, NULL, cmd);
	get_arguments(cmd, &tokenlist);
	clear_tokenlist(&tokenlist);
	if (cmd->args)
	{
		cmd->exec_name = cmd->args[0];
		if (cmd->nb_args > 0)
			get_options(cmd);
	}
	clear_tokenlist(&tokenlist);
	return (1);
}
