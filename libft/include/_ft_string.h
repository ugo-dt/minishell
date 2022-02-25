/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_string.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:42:46 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/06 13:00:23 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_STRING_H
# define _FT_STRING_H	1

# if !defined _LIBFT_HEADER
#  error "Do not include "_ft_string.h" directly. Use "libft.h" instead."
# endif

# include "_ft_char.h"
# include "_ft_mem.h"
# include <stdlib.h>

/* The ft_atoi() function converts the initial portion
 * of the string pointed by str to an int representation. */
extern int		ft_atoi(const char *str);

/* The ft_itoa() function converts an integer value to
 * a null-terminated string. */
extern char		*ft_itoa(int n);

/* Returns the length from s to the next character c
 * or the next '\\0' character. */
extern size_t	ft_len_to_char(const char *s, char c);

/* Returns the length from s to the next space character (using ft_isspace())
 * or the next '\\0' character. */
size_t			ft_len_to_space(const char *s);
/* 
 * The ft_str_tolower() function creates a NULL-terminated lowercase copy of
 * the string src.
 *
 * @returns A pointer to the first character on the newly created string.
 */
extern char		*ft_str_tolower(char *dst, const char *src);

/* The ft_str_toupper() function creates a NULL-terminated uppercase copy of
 * the string src.
 *
 * @returns A pointer to the first character on the newly created string.
 */
extern char		*ft_str_toupper(char *dst, const char *src);

/* 
 * The ft_strcmp() and ft_strncmp() functions lexicographically compare the
 * null-terminated strings s1 and s2.
 * 
 * @returns 0 if the strings are identical.
 */
extern int		ft_strcmp(const char *s1, const char *s2);

/* 
 * The ft_strcmp() and ft_strncmp() functions lexicographically compare the
 * null-terminated strings s1 and s2.
 * 
 * The ft_strncmp() function compares not more than n characters.
 * Because ft_strncmp() is designed for comparing strings rather than binary
 * data, characters that appear after a '\\0' character are not compared.
 * 
 * @returns 0 if the strings are identical.
 */
extern int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* 
 * The ft_strdup() function allocates sufficient memory for a copy of the string
 * s1, does the copy, and returns a pointer to it. The pointer may subsequently
 * be used as an argument tothe function free(3).
 * 
 * If insufficient memory is available, NULL is returned.
 */
extern char		*ft_strdup(const char *s);

/* 
 * The ft_strndup() function allocates sufficient memory for a copy of the string
 * s1, does the copy, and returns a pointer to it. The pointer may subsequently
 * be used as an argument tothe function free(3).
 * 
 * The function copies at most n characters from the string s1 and always
 * NULL-terminates the copied string.
 * 
 * If insufficient memory is available, NULL is returned.
 */
extern char		*ft_strndup(const char *s, size_t n);

/* 
 * The ft_strjoin() function appends the s1 string to the dest s2,
 * overwriting the terminating null byte ('\\0') at the end of s1,
 * and then adds a terminating null byte.
 * 
 * If either of the strings is NULL, the function returns NULL.
 * 
 * Memory for the new string is obtained with malloc(3),
 * and can be freed with free(3);
 */
extern char		*ft_strjoin(const char *s1, const char *s2);

/* 
 * The ft_strjoin_3() function appends the a string to the b string,
 * then to the c string. (ex: "a", "b", "c" -> "abc")
 * 
 * It overwrites the terminating null byte ('\\0') at the end of a and b,
 * and adds a terminating null byte.
 * 
 * If one of the strings is NULL, the function returns NULL.
 * 
 * Memory for the new string is obtained with malloc(3),
 * and can be freed with free(3);
 */
extern char		*ft_strjoin_3(const char *a, const char *b, const char *c);

/* 
 * The ft_strcat() and function append a copy of the null-terminated
 * string s2 to the end of the null-terminated string s1, then add a terminating
 * '\\0'. The string s1 must have sufficient space to hold the result.
 */
extern char		*ft_strcat(char *s1, const char *s2);

/* 
 * The ft_strcat() and function append a copy of the null-terminated
 * string s2 to the end of the null-terminated string s1, then add a terminating
 * '\\0'. The string s1 must have sufficient space to hold the result. 
 * 
 * The ft_strncat function appends not more than n characters from s2,
 * and then adds a terminating '\\0'.
 */
extern char		*ft_strncat(char *s1, const char *s2, size_t n);

/* 
 * The ft_strlcat() function appends the NUL-terminated
 * string src to the end of dst.
 * It will append at most size - ft_strlen(dst) - 1 bytes,
 * null-terminating the result.
 * 
 * The function returns the total length of the string it tried to create.
 */
extern size_t	ft_strlcat(char *dst, const char *src, size_t size);

/* The ft_strcpy() function copy the string src to dst
 * (including the terminating '\\0' character.) */
extern char		*ft_strcpy(char *dest, const char *src);

/* 
 * The ft_strncpy() function copy the string src to dst
 * (including the terminating '\\0' character.)
 *
 * The function copy at most len characters from src into dst.
 * If src is less than n characters long, the remainder of dst is filled with
 * '\\0' characters. Otherwise, dst is not terminated.
 */
extern char		*ft_strncpy(char *s1, const char *s2, size_t n);

/* The ft_strlcpy() function copies up to size - 1 characters from
 * the NUL-terminated string src to dst, NUL-terminating the result. */
extern size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/* The ft_strlen() function computes the length of the string s. */
extern size_t	ft_strlen(const char *s);

/* The ft_strnlen() function attempts to compute the length of s,
 * but never scans beyond the first maxlen bytes of s. */
extern size_t	ft_strnlen(const char *s, size_t maxlen);

/* 
 * The ft_strnstr() function locates the first occurrence of the null-terminated
 * string needle in the string haystack, where not more than len characters are
 * searched. Characters that appear after a '\\0' character are not searched.
 */
extern char		*ft_strnstr(const char *haystack, const char *needle, size_t n);

/* 
 * The ft_strchr() function locates the first occurrence of the char c in the
 * string pointed to by s. The terminating null character is considered to be
 * part of the string; therefore if c is '\\0', the function locates the
 * terminating '\\0'.
 * 
 * The function returns NULL if it cannot find the character c in the string s.
 */
extern char		*ft_strchr(const char *s, int c);

/* 
 * The ft_strchr() function locates the first occurrence of the char c in the
 * string pointed to by s. The terminating null character is considered to be
 * part of the string; therefore if c is '\\0', the function locates the
 * terminating '\\0'.
 * 
 * The function returns NULL if it cannot find the character c in the string s.
 *
 * The ft_strrchr() function is identical to ft_strchr(),
 * except it locates the last occurrence of c.
 */
extern char		*ft_strrchr(const char *s, int c);

/* libft exclusive functions */

/* 
 * The ft_strmapi() applies the given function f to each character of the
 * string s to create a new string (with malloc(3))
 * resulting from successive applications of f.
 */
extern char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));

/* 
 * The ft_substr() function allocates memory with malloc(3) then returns a
 * string of len characters (or up to the first '\\0' encountered), and starting
 * from index start of s.
 */
extern char		*ft_substr(char *s, unsigned int start, size_t len);

/*
 * The ft_strtrim() function allocates memory with malloc(3) then returns the
 * same string as s1, without the characters specified in set, at the start
 * and at the end of s1.
 */
extern char		*ft_strtrim(char *s1, char *set);

/* _FT_STRING_H */
#endif
