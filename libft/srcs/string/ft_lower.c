/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:04:04 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/26 10:05:34 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "_ft_string.h"

char	*ft_lower(char *s)
{
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (ft_isupper(s[i]))
			*s = ft_tolower(s[i]);
		i++;
	}
	return (s);
}
