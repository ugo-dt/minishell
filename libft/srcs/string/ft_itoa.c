/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:15:42 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/26 12:51:05 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

static int	get_nb(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static char	*create_string(int len, int nb, int n)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(*dest) * len + 1 + (nb < 0));
	if (dest)
	{
		if (n < 0)
		{
			dest[i] = '-';
			len++;
		}
		i = len - 1;
		while (nb >= 10)
		{
			dest[i] = nb % 10 + 48;
			nb /= 10;
			i--;
		}
		dest[i] = nb % 10 + 48;
		dest[len] = '\0';
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	unsigned int	nb;

	nb = get_nb(n);
	len = digits(nb);
	return (create_string(len, nb, n));
}
