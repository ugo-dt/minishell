/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_char.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:45:01 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/06 13:00:01 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_CHAR_H
# define _FT_CHAR_H	1

# if !defined _LIBFT_HEADER
#  error "Do not include "_ft_char.h" directly. Use "libft.h" instead."
# endif

/* The ft_islower() function tests for any lower-case letters */
extern int		ft_islower(char c);
/* The ft_isupper() function tests for any upper-case letter. */
extern int		ft_isupper(char c);

/* The ft_tolower() function converts an upper-case letter to the corresponding
 * lower-case letter. The argument must be representable as an unsigned char.*/
extern int		ft_tolower(int c);
/* The ft_toupper() function converts an lower-case letter to the corresponding
 * upper-case letter. The argument must be representable as an unsigned char.*/
extern int		ft_toupper(int c);

/* The ft_isalpha() function tests for any character
 * for which isupper(3) or islower(3) is true. */
extern int		ft_isalpha(int c);
/* The ft_isdigit() function tests for a decimal digit character. */
extern int		ft_isdigit(int c);
/* The ft_isalnum() function tests for any character for which
 * ft_isalpha() or ft_isdigit() is true. */
extern int		ft_isalnum(int c);

/* The isascii() function tests for an ASCII character, which is any character
 * between 0 and decimal 127 inclusive. */
extern int		ft_isascii(int c);

/* The ft_isprint() function tests for any printing character,
 * including space (' '). */
extern int		ft_isprint(int c);

/* The ft_isspace() function tests for the white-space characters.
 * This includes the following standard characters:
 * '\\t'   '\\n'    '\\v'    '\\f'    '\\r'    ' ' */
extern int		ft_isspace(char c);

/* _FT_CHAR_H */
#endif
