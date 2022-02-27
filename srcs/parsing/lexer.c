/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:36:50 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/27 15:37:31 by ugdaniel         ###   ########.fr       */
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

static size_t	word_len(const char *word)
{
	size_t	i;
	char	q;

	i = 0;
	while (word[i])
	{
		if (word[i] == '\'' || word[i] == '\"')
		{
			q = word[i++];
			while (word[i] && word[i] != q)
				i++;
		}
		else
		{
			if (is_token_separator(word[i]))
				break ;
			i++;
		}
	}
	return (i);
}

static void lexer_word(const char *line, size_t *i, t_token **tokenlist)
{
	char	quote;
	size_t	size;

	quote = line[*i];
	size = word_len(&line[*i]);
	tokenlist_add_back(tokenlist, new_token(TOKEN_WORD, &line[*i], size));
	*i += size;
}

t_token	*lexer(const char *line)
{
	size_t	i;
	t_token	*tokenlist;
	TOKEN	last_token;

	i = 0;
	tokenlist = NULL;
	last_token = -1;
	while (line[i])
	{
		if (line[i] == '\0' || line[i] == '#') // end of input
		{
			tokenlist_add_back(&tokenlist, new_token(NO_TOKEN, NULL, 0));
			break ;
		}
		else if (line[i] == '\n') // end of input, newline
			tokenlist_add_back(&tokenlist, new_token(TOKEN_NEWLINE, NULL, 0));
		else if (line[i] == '>' || line[i] == '<') // redirections
		{
			if (lexer_chevrons(line, &i, tokenlist, &last_token) == 1)
				continue;
		}
		else if (ft_isspace(line[i])) // discard spaces and tabulations
		{
			last_token = NO_TOKEN;
			i++;
			continue ;
		}
		else if (line[i] == '|') // pipelines: command output is redirected to input of the next command
			last_token = TOKEN_PIPE;
		else // simple word (command name, options, arguments, filenames for redirections)
		{
			last_token = TOKEN_WORD;
			lexer_word(line, &i, &tokenlist);
			continue ;
		}
		tokenlist_add_back(&tokenlist, new_token(last_token, NULL, 0)); // chevrons and pipes use this
		i++;
	}
	return (tokenlist);
}
