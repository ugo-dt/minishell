/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:01:49 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/22 10:46:52 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H	1

# if !defined _LIBFT_HEADER
#  error "Do not include "_ft_printf.h" directly. Use "libft.h" instead."
# endif

# include "_ft_math.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define ASCII_0			48

/* The function ft_putstr_len() writes the string pointed to by s to the file
 * descriptor fd.
 * @returns The number of characters written. */
ssize_t	ft_putstr_len(char *s, int fd);

/* The function ft_putchar_len() writes the character c to the file descriptor
 * fd.
 * @returns The number of characters written. */
ssize_t	ft_putchar_len(char c, int fd);

/* The function ft_putint_len() writes the number nb to the file
 * descriptor fd.
 * @returns The number of characters written. */
ssize_t	ft_putint_len(int nb, int fd);

/* The function ft_putuint_len() writes the unsigned number nb to the file
 * descriptor fd.
 * @returns The number of characters written. */
ssize_t	ft_putuint_len(unsigned int nb, int fd);

/* The function ft_putint_len() writes the number fd in hexadecimal to the file
 * descriptor fd.
 * @returns The number of characters written. */
ssize_t	ft_puthex_len(char x, unsigned int nb, int fd);

ssize_t	ft_putaddr_len(size_t nb, int fd);

ssize_t	ft_putulong_len(size_t nb, int fd);

ssize_t	ft_putlong_len(long nb, int fd);

int		ft_dprintf_internal(int fd, const char *f, va_list *ap);

int		ft_dprintf(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);

/* _FT_PRINTF_H */
#endif