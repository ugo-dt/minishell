/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:31:22 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/26 13:01:01 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*d;

	if (!s1 || !s2)
		return (NULL);
	d = malloc(sizeof(*d) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!d)
		return (NULL);
	return (ft_strcat(ft_strcpy(d, s1), s2));
}
