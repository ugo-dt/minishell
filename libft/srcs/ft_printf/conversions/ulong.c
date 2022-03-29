/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:56:35 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/26 13:35:42 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putchar_size(char c, int fd);

ssize_t	ft_putulong_size(size_t nb, int fd)
{
	int		done;

	done = 0;
	if (nb < 10)
		done += ft_putchar_size(nb + 48, fd);
	else
	{
		done += ft_putulong_size(nb / 10, fd);
		done += ft_putulong_size(nb % 10, fd);
	}
	return (done);
}
