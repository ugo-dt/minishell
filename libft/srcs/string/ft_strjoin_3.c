/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:18:38 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/26 17:41:56 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_3(const char *s1, const char *s2, const char *s3)
{
	char			*dst;

	if (!s1 || !s2 || !s3)
		return (NULL);
	dst = malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3)) + 1);
	if (!dst)
		return (NULL);
	return (ft_strcat(ft_strcat(ft_strcpy(dst, s1), s2), s3));
}
