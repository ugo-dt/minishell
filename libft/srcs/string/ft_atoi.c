/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:28:43 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/26 12:51:05 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef INT_MAX
# define INT_MAX 2147483647
#endif
#ifndef INT_MIN
# define INT_MIN -2147483648
#endif

/*
int	ft_atoi(const char *nptr)
{
	int		sign;
	int		result;

	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	sign = 1;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + *nptr - 48;
		nptr++;
	}
	return (result * sign);
}
*/

int	ft_atoi(const char *s)
{
	int		digit;
	int		sign;
	int		result;

	if (!s)
		return (0);
	while (*s == ' ')
		s++;
	sign = 1;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	result = 0;
	while (*s >= '0' && *s <= '9')
	{
		digit = *s++ - 48;
		if (result * sign > INT_MAX / 10
			|| ((sign == 1 && result >= 214748364 && digit >= 7)))
			return (INT_MAX);
		if (result * sign < INT_MIN / 10
			|| ((sign == -1 && result >= 214748364 && digit >= 8)))
			return (INT_MIN);
		result = result * 10 + digit;
	}
	return (result * sign);
}
