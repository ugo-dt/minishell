/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:29:27 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/09/28 15:29:27 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "_ft_string.h"

char	*ft_str_toupper(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		if (ft_islower(src[i]))
			dst[i] = (char)ft_toupper(src[i]);
		else
			dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
