/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf-internal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:46:57 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/26 21:20:27 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putchar_size(char c, int fd);
ssize_t	ft_putstr_size(char *s, int fd);
ssize_t	ft_putaddr_size(size_t nb, int fd);
ssize_t	ft_putint_size(int nb, int fd);
ssize_t	ft_putuint_size(uint32_t nb, int fd);
ssize_t	ft_puthex_size(char x, unsigned int nb, int fd);
ssize_t	ft_putulong_size(size_t nb, int fd);
ssize_t	ft_putlong_size(long nb, int fd);

ssize_t	convert_identifier(int fd, const char *f, va_list *ap)
{
	if (*f == '%')
		return (ft_putchar_size('%', fd));
	else if (*f == 'c')
		return (ft_putchar_size(va_arg(*ap, int), fd));
	else if (*f == 's')
		return (ft_putstr_size(va_arg(*ap, char *), fd));
	else if (*f == 'p')
		return (ft_putstr_size("0x\0", fd)
			+ ft_putaddr_size(va_arg(*ap, size_t), fd));
	else if (*f == 'd' || *f == 'i')
		return (ft_putint_size(va_arg(*ap, int), fd));
	else if (*f == 'u')
		return (ft_putuint_size(va_arg(*ap, uint32_t), fd));
	else if (*f == 'x' || *f == 'X')
		return (ft_puthex_size(*f, va_arg(*ap, int), fd));
	else if (*f == 0)
		write(fd, "", 1);
	return (0);
}

int	ft_dprintf_internal(int fd, const char *f, va_list *ap)
{
	int		done;

	done = 0;
	while (*f)
	{
		if (*f != '%')
			done += ft_putchar_size(*f++, fd);
		else
		{
			f++;
			if (*f == 'l')
			{
				f++;
				if (*f == 'u')
					done += ft_putulong_size(va_arg(*ap, size_t), fd);
				else if (*f == 'd' || *f == 'i')
					done += ft_putlong_size(va_arg(*ap, long), fd);
			}
			else
				done += convert_identifier(fd, f, ap);
			f++;
		}
	}
	return (done);
}
