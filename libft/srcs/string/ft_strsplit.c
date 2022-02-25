/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:19:04 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/06 13:01:05 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "_ft_string.h"

static int	ft_wordslen(const char *s, char c, int i)
{
	int	n;

	n = 0;
	while (s[i++] != c && s[i] != '\0')
		n++;
	return (n);
}

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	words;
	int	j;

	i = 0;
	words = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c && j > 0) || (s[i] != c && s[i + 1] == '\0'))
		{
			words++;
			j = 0;
		}
		else if (s[i] != c)
			j++;
		i++;
	}
	return (words);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		n;
	int		i[2];

	i[1] = 0;
	i[0] = 0;
	n = 0;
	split = malloc(8 * (ft_countwords(s, c) + 1));
	if (!s || !c || !split)
		return (NULL);
	while (ft_countwords(s, c) > n)
	{
		i[1] = 0;
		while (s[i[0]] == c)
			i[0]++;
		split[n] = malloc(ft_wordslen(s, c, i[0]) + 2);
		if (!split[n])
			return (NULL);
		while (s[i[0]] != c && s[i[0]] != '\0')
			split[n][i[1]++] = s[i[0]++];
		split[n++][i[1]] = '\0';
	}
	split[n] = NULL;
	return (split);
}
