/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:56:58 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/18 17:13:03 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "_ft_printf.h"

ssize_t	ft_putstr_len(char *s, int fd)
{
	ssize_t	i;

	if (!s)
		return (write(fd, "(null)", 6));
	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
	return (i);
}
