/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:51:43 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/26 13:35:42 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putchar_size(char c, int fd);

/* The function ft_putuint_size() writes the unsigned number nb to the file
 * descriptor fd.
 * @returns The number of characters written. */
ssize_t	ft_putuint_size(uint32_t nb, int fd)
{
	ssize_t	done;

	done = 0;
	if (nb < 10)
		done += ft_putchar_size(nb + 48, fd);
	else
	{
		done += ft_putuint_size(nb / 10, fd);
		done += ft_putuint_size(nb % 10, fd);
	}
	return (done);
}
