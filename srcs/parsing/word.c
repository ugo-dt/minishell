/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:30:28 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/30 18:12:51 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

void	lexer_word(const char *line, size_t *i, t_token **tokenlist)
{
	size_t	size;

	size = word_len(&line[*i]);
	tokenlist_add_back(tokenlist, new_token(TOKEN_WORD, &line[*i], size));
	*i += size;
}

size_t	word_len(const char *word)
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
			if (word[i])
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
