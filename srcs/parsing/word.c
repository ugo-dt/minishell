/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:30:28 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/27 22:15:22 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

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
