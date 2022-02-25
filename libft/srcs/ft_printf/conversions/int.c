/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:23:32 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/18 16:29:22 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "_ft_printf.h"

ssize_t	ft_putint_len(int nb, int fd)
{
	ssize_t	done;

	done = 0;
	if (nb == -2147483648)
	{
		done += ft_putint_len(-214748364, fd);
		done += ft_putchar_len('8', fd);
	}
	else if (nb < 0)
	{
		done += ft_putchar_len('-', fd);
		done += ft_putint_len(-nb, fd);
	}
	else if (nb < 10)
		done += ft_putchar_len(nb + ASCII_0, fd);
	else
	{
		done += ft_putint_len(nb / 10, fd);
		done += ft_putint_len(nb % 10, fd);
	}
	return (done);
}
