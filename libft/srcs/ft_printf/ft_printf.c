/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:48:29 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/26 13:07:53 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dprintf_internal(int fd, const char *f, va_list *ap);

/* Write formatted output to stdout from the format string FORMAT.
 * @returns The number of written characters. */
int	ft_printf(const char *restrict format, ...)
{
	int		done;
	va_list	ap;

	va_start(ap, format);
	done = ft_dprintf_internal(STDOUT_FILENO, format, &ap);
	va_end(ap);
	return (done);
}
