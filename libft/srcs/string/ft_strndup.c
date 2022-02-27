/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:41:36 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/26 12:31:53 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "_ft_string.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*d;

	len = ft_strlen(s) + 1;
	if (len > n)
		len = n;
	d = malloc(sizeof(*d) * len);
	if (!d)
		return (NULL);
	return (ft_memcpy(d, s, len));
}

/*
char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	size_t	len;
	char	*dst;

	len = ft_strlen(s) + 1;
	if (len > n)
		len = n;
	dst = malloc(sizeof(char) * len);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
*/