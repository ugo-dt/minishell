/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:23:32 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/26 13:35:42 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putchar_size(char c, int fd);

/* The function ft_putint_size() writes the number nb to the file
 * descriptor fd.
 * @returns The number of characters written. */
ssize_t	ft_putint_size(int nb, int fd)
{
	ssize_t	done;

	done = 0;
	if (nb == INT_MIN)
	{
		done += ft_putint_size(INT_MIN / 10, fd);
		done += ft_putchar_size('8', fd);
	}
	else if (nb < 0)
	{
		done += ft_putchar_size('-', fd);
		done += ft_putint_size(-nb, fd);
	}
	else if (nb < 10)
		done += ft_putchar_size(nb + 48, fd);
	else
	{
		done += ft_putint_size(nb / 10, fd);
		done += ft_putint_size(nb % 10, fd);
	}
	return (done);
}
