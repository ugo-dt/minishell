/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:29:51 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/26 13:35:42 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putchar_size(char c, int fd);

/* The function ft_puthex_size() writes the number fd in hexadecimal to the file
 * descriptor fd.
 * @returns The number of characters written. */
ssize_t	ft_puthex_size(char x, unsigned int nb, int fd)
{
	ssize_t	done;
	int		caps;

	if (x == 'X')
		caps = 55;
	else
		caps = 87;
	done = 0;
	if (nb < 10)
		done += ft_putchar_size(nb + 48, fd);
	else if (nb < 16)
		done += ft_putchar_size(nb + caps, fd);
	else
	{
		done += ft_puthex_size(x, nb / 16, fd);
		done += ft_puthex_size(x, nb % 16, fd);
	}
	return (done);
}
