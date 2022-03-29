/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:36:50 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/29 12:17:05 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	lexer_chevrons(const char *s, size_t *i, t_token *lst, TOKEN *last)
{
	if (s[*i] == '>')
	{
		if (*last == TOKEN_GREAT)
		{
			change_last_token_type(&lst, TOKEN_GREATGREAT);
			(*i)++;
			return (1);
		}
		*last = TOKEN_GREAT;
	}
	else if (s[*i] == '<')
	{
		if (*last == TOKEN_LESS)
		{
			change_last_token_type(&lst, TOKEN_LESSLESS);
			(*i)++;
			return (1);
		}
		*last = TOKEN_LESS;
	}
	return (0);
}

static void	lexer_word(const char *line, size_t *i, t_token **tokenlist)
{
	size_t	size;

	size = word_len(&line[*i]);
	tokenlist_add_back(tokenlist, new_token(TOKEN_WORD, &line[*i], size));
	*i += size;
}

/*
static int	more_lexer_2(
	const char *line, size_t *i, t_token **tokenlist, TOKEN *last_token)
{

	else
	{
		*last_token = TOKEN_WORD;
		lexer_word(line, &(*i), &(*tokenlist));
		return (1);
	}
}*/

static int	more_lexer(
	const char *line, size_t *i, t_token **tokenlist, TOKEN *last_token)
{
	if (line[*i] == '>' || line[*i] == '<')
	{
		if (lexer_chevrons(line, &(*i), *tokenlist, &(*last_token)) == 1)
			return (1);
	}
	else if (ft_isspace(line[*i]))
	{
		*last_token = NO_TOKEN;
		(*i)++;
		return (1);
	}
	else if (line[*i] == '|')
		*last_token = TOKEN_PIPE;
	else
	{
		//return (more_lexer_2(line, i, tokenlist, last_token));
		*last_token = TOKEN_WORD;
		lexer_word(line, &(*i), &(*tokenlist));
		return (1);
	}
	return (0);
}

t_token	*lexer(const char *line, size_t i)
{
	int		done;
	t_token	*tokenlist;
	TOKEN	last_token;

	tokenlist = NULL;
	last_token = -1;
	while (line[i])
	{
		if (line[i] == '\0' || line[i] == '#')
		{
			tokenlist_add_back(&tokenlist, new_token(NO_TOKEN, NULL, 0));
			break ;
		}
		else if (line[i] == '\n')
			tokenlist_add_back(&tokenlist, new_token(TOKEN_NEWLINE, NULL, 0));
		else
		{
			done = more_lexer(line, &i, &tokenlist, &last_token);
			if (done == 1)
				continue ;
		}
		tokenlist_add_back(&tokenlist, new_token(last_token, NULL, 0));
		i++;
	}
	return (tokenlist);
}
