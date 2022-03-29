/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:17:50 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/18 20:54:44 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "errors.h"

int	unexpected_token(unsigned int t)
{
	ft_printf("%s: syntax error near unexpected token", SHELL_NAME);
	if (t == TOKEN_NEWLINE)
		ft_printf(": 'newline'");
	else if (t == TOKEN_GREAT || t == TOKEN_GREATGREAT)
		ft_printf(": '>'");
	else if (t == TOKEN_LESS || t == TOKEN_LESSLESS)
		ft_printf(": '<'");
	else if (t == TOKEN_PIPE)
		ft_printf(": '|'");
	ft_printf("\n");
	g_sh.exit_value = 2;
	return (1);
}
/*
int	check_filename(const char *s)
{
	while (s && *s)
	{
		if (*s == '<' || *s == '>')
		{
			s++;
			if (*s == '<' || *s == '>')
				s++;
			while (ft_isspace(*s))
				s++;
			if (*s == '|')
				return (unexpected_token(*s));
		}
		if (*s)
			s++;
	}
	return (0);
}

int	check_redirections(const char *s)
{
	char		redir;
	char		redir2;
	const char	*line;

	redir = 0;
	redir2 = 0;
	line = s;
	while (*line)
	{
		if (*line == '<' || *line == '>')
		{
			if (redir2 || (redir && redir != *line))
				return (unexpected_token(*line));
			if (redir == 0)
				redir = *line;
			else if (redir == *line)
				redir2 = *line;
		}
		if (*line)
			line++;
	}
	return (check_filename(s));
}*/

int	check_token_order(t_token **list)
{
	t_token	*t;
	t_token	*t2;

	t = *list;
	while (t)
	{
		if (t->type >= TOKEN_GREAT && t->type <= TOKEN_PIPE)
		{
			t2 = t->next;
			if (!t2)
				return (unexpected_token(TOKEN_NEWLINE));
			if (t2->type != TOKEN_WORD)
				return (unexpected_token(t2->type));
		}
		t = t->next;
	}
	return (0);
}

int	check_quotes(const char *line)
{
	char	quote;

	quote = 0;
	while (*line)
	{
		if (*line == '\'')
		{
			if (quote == 0)
				quote = '\'';
			else if (quote == '\'')
				quote = 0;
		}
		else if (*line == '\"')
		{
			if (quote == 0)
				quote = '\"';
			else if (quote == '\"')
				quote = 0;
		}
		line++;
	}
	if (quote)
		return (set_error_message(BAD_QUOTES_NEWLINE, quote_type(quote), 1));
	return (0);
}
