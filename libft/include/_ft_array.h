/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_array.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:36:11 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/18 15:36:26 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_ARRAY_H
# define _FT_ARRAY_H	1

# if !defined _LIBFT_HEADER
#  error Do not include "_ft_array.h" directly. Use "libft.h" instead.
# endif

# include "_ft_string.h"
# include "_ft_write.h"
# include <stdlib.h>

/* The ft_array_size() function returns the size of a NULL terminated
 * two-dimensional array. */
size_t			ft_array_size(void **arr);

/* The ft_free_array() function frees a each element from a two-dimensional
 * array, starting from index 0 up to the first NULL element encountered. */
extern void		ft_free_array(void **arr);

/* The ft_free_array_n() function frees up to n elements from a
 * two-dimensional array, then frees the pointer to the array. */
extern void		ft_free_array_n(void **tab, size_t max);

/*
 * The ft_copy_array() function returns a copy of the NULL-terminated
 * two-dimensional array arr. The function only copies up to the first
 * NULL encountered.
 * 
 * The memory for the copy is obtained using malloc(3),
 * and can be freed with free(3);
 */
extern char		**ft_copy_array(char **arr);

/* 
 * The ft_split() function splits a string it into words, and returns them as
 * a NULL-terminated array of strings.
 * 
 * A "word" is defined as a part of a string delimited by the character c,
 * or by the start/end of the string.
 * 
 * The memory for the array is obtained using malloc(3),
 * and can be freed with free(3);
 */
extern char		**ft_split(const char *s, char c);

/*
 * Print every string in the array arr, followed by a newline,
 * on the file descriptor fd.
 * 
 * The function stops at the first NULL string encountered.
 */
extern void		ft_print_array_fd(const char **arr, int fd);

/* Sort an array of string using ft_strcmp(). */
extern void		ft_sort_array(char **array);

/* _FT_ARRAY_H */
#endif
