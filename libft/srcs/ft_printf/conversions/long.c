/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:03:20 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/18 16:26:46 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "_ft_printf.h"

ssize_t	ft_putlong_len(long nb, int fd)
{
	ssize_t	done;

	done = 0;
	if (nb <= -9223372036854775807)
	{
		done += ft_putlong_len(-922337203685477580, fd);
		done += ft_putchar_len(ft_abs((int)(nb % 10)) + 48, fd);
	}
	else if (nb < 0)
	{
		done += ft_putchar_len('-', fd);
		done += ft_putlong_len(-nb, fd);
	}
	else if (nb < 10)
		done += ft_putchar_len(nb + ASCII_0, fd);
	else
	{
		done += ft_putlong_len(nb / 10, fd);
		done += ft_putlong_len(nb % 10, fd);
	}
	return (done);
}
