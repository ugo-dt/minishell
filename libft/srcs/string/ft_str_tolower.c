/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:23:31 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/09/28 15:23:31 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "_ft_string.h"

char	*ft_str_tolower(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		if (ft_isupper(src[i]))
			dst[i] = (char)ft_tolower(src[i]);
		else
			dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
