/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:05:16 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/26 10:05:27 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "_ft_string.h"

char	*ft_upper(char *s)
{
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (ft_islower(s[i]))
			*s = ft_toupper(s[i]);
		i++;
	}
	return (s);
}
