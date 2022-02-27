/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:32:03 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/27 22:34:18 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "shell.h"

/*
void	print_token_details(t_token *t)
{
	printf("DEBUG: ---TOKEN---\n");
	printf("DEBUG: type: ");
	if (t->word)
		printf("WORD: |");
	else
		printf("Operator: ");
	if (t->type == TOKEN_NEWLINE)
		printf("'newline'\n");
	if (t->type == TOKEN_GREAT)
		printf(">\n");
	if (t->type == TOKEN_LESS)
		printf("<\n");
	if (t->type == TOKEN_GREATGREAT)
		printf(">>\n");
	if (t->type == TOKEN_LESSLESS)
		printf("<<\n");
	if (t->type == TOKEN_PIPE)
		printf("|\n");
	if (t->word)
	{
		for (size_t j=0;j<t->wsize;j++)
			printf("%c", t->word[j]);
		printf("|\n");
	}
	printf("DEBUG: --- END ---\n");
}
*/

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
			cmd->args[i++] = parameter_expansion(temp->word, temp->wsize, 0);
		else if (prev && prev->type == TOKEN_WORD && temp->type == TOKEN_WORD)
			cmd->args[i++] = parameter_expansion(temp->word, temp->wsize, prev->type);
		prev = temp;
		temp = temp->next;
	}
	if (cmd->args)
		cmd->exec_name = cmd->args[0];
	return (1);
}

static int	parse_tokens_to_arguments(t_cmd *cmd, t_token **list)
{
	t_token	*temp;
	t_token	*prev;
	t_cmd	*c;

	c = cmd;
	temp = *list;
	prev = NULL;
	while (temp)
	{
		if (temp->type == TOKEN_PIPE)
		{
			c->next = new_cmd();
			parse_tokens_to_arguments(c->next, &temp->next);
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
				ft_rediraddback(&c->redir, new_redirection(temp->word, temp->wsize, prev->type));
		}
		prev = temp;
		temp = temp->next;
	}
	get_arguments(c, list);
	return (1);
}

static int	parse_string(t_cmd *cmd, const char *line)
{
	size_t	i;
	t_token	*tokenlist;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	tokenlist = lexer(line);
	if (!tokenlist)
		return (0);
	if (check_token_order(&tokenlist) != 0)
		return (0);
	parse_tokens_to_arguments(cmd, &tokenlist);
	clear_tokenlist(&tokenlist);
	return (1);
}

int	parse_command(t_cmd *cmd, const char *line)
{
	if (!line)
		return (0);
	ft_memset(cmd, 0, sizeof(t_cmd));
	if (!parse_string(cmd, line))
		return (0);
	if (cmd->args)
	{
		cmd->exec_name = cmd->args[0];
		if (cmd->nb_args > 0)
			ft_setenv("_", cmd->args[cmd->nb_args - 1], 1);
	}
	return (1);
}
