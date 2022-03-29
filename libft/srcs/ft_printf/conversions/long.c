/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:03:20 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/26 13:35:42 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putchar_size(char c, int fd);

ssize_t	ft_putlong_size(long nb, int fd)
{
	ssize_t	done;

	done = 0;
	if (nb <= -9223372036854775807)
	{
		done += ft_putlong_size(-922337203685477580, fd);
		done += ft_putchar_size(ft_abs((int)(nb % 10)) + 48, fd);
	}
	else if (nb < 0)
	{
		done += ft_putchar_size('-', fd);
		done += ft_putlong_size(-nb, fd);
	}
	else if (nb < 10)
		done += ft_putchar_size(nb + 48, fd);
	else
	{
		done += ft_putlong_size(nb / 10, fd);
		done += ft_putlong_size(nb % 10, fd);
	}
	return (done);
}
