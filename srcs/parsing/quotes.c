/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:24:38 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/04 17:20:55 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

char	*remove_quotes(char *str)
{
	size_t	i;
	size_t	size;
	char	q;
	char	*dest;

	q = 0;
	size = ft_strlen(str) + 1;
	dest = ft_xmalloc(sizeof(char) * size);
	ft_memset(dest, 0, size);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			q = str[i++];
			while (str[i] && str[i] != q)
				ft_strncat(dest, &str[i++], 1);
			if (str[i] == q)
				i++;
		}
		else
			ft_strncat(dest, &str[i++], 1);
	}
	free(str);
	return (dest);
}
