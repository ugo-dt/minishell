/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:39:36 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/18 16:27:52 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "_ft_printf.h"

ssize_t	ft_putaddr_len(size_t nb, int fd)
{
	ssize_t	done;

	done = 0;
	if (nb < 10)
		done += ft_putchar_len(nb + ASCII_0, fd);
	else if (nb < 16)
		done += ft_putchar_len(nb + 87, fd);
	else
	{
		done += ft_putaddr_len(nb / 16, fd);
		done += ft_putaddr_len(nb % 16, fd);
	}
	return (done);
}
