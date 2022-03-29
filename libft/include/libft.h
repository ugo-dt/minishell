/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:51:19 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/29 12:07:10 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H	1

/* Dependencies
 * malloc(3), free(3), stdarg(3) */
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

/*
 * ARRAY functions 
 */

/* The ft_array_size() function returns the size of a NULL terminated
 * two-dimensional array. */
size_t	ft_array_size(void **arr);

/* The ft_free_array() function frees a each element from a two-dimensional
 * array, starting from index 0 up to the first NULL element encountered. */
void	ft_free_array(void **arr);

/* The ft_free_array_n() function frees up to n elements from a
 * two-dimensional array, then frees the pointer to the array. */
void	ft_free_array_n(void **tab, size_t n);

/*
 * The ft_copy_array() function returns a copy of the NULL-terminated
 * two-dimensional array arr. The function only copies up to the first
 * NULL encountered.
 * 
 * The memory for the copy is obtained using malloc(3),
 * and can be freed with free(3);
 */
char	**ft_copy_array(char **arr);

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
char	**ft_split(const char *s, char c);

/*
 * Print every string in the array arr, followed by a newline,
 * on the file descriptor fd.
 * 
 * The function stops at the first NULL string encountered.
 */
void	ft_print_array_fd(const char **arr, int fd);

/* Sort an array of strings using ft_strcmp(). */
void	ft_sort_array(char **array);

/* CHAR functions */

/* The ft_islower() function tests for any lower-case letters */
int		ft_islower(int c);

/* The ft_isupper() function tests for any upper-case letter. */
int		ft_isupper(int c);

/* The ft_tolower() function converts an upper-case letter to the corresponding
 * lower-case letter. The argument must be representable as an unsigned char.*/
int		ft_tolower(int c);

/* The ft_toupper() function converts an lower-case letter to the corresponding
 * upper-case letter. The argument must be representable as an unsigned char.*/
int		ft_toupper(int c);

/** The ft_isalpha() function tests for any character
 * for which isupper(3) or islower(3) is true.
 *
 * @return Zero if the character tests false and returns non-zero if the
 * character tests true.
 */
int		ft_isalpha(int c);

/** The ft_isdigit() function tests for a decimal digit character. 
 *
 * This includes the following characters only:
 * '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
 * 
 * @return Zero if the character tests false and return non-zero if the
 * character tests true.
 */
int		ft_isdigit(int c);

/* The ft_isalnum() function tests for any character for which
 * ft_isalpha() or ft_isdigit() is true. */
int		ft_isalnum(int c);

/* The isascii() function tests for an ASCII character, which is any character
 * between 0 and decimal 127 inclusive. */
int		ft_isascii(int c);

/* The ft_isprint() function tests for any printing character,
 * including space (' '). */
int		ft_isprint(int c);

/* The ft_isspace() function tests for the white-space characters.
 * This includes the following standard characters:
 * '\\t'   '\\n'    '\\v'    '\\f'    '\\r'    ' ' */
int		ft_isspace(int c);

/*
 * LIST functions 
 */

/**
 * struct s_list
 * 
 * @param content Pointer to any type of data;
 * @param next The address of the next link of the list (NULL if last).
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

/** Adds a new element at the end of the list.
 * 
 * @param lst The first element of the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/** Adds a new element at the start of the list.
 * 
 * @param lst The first element of the list. Can be NULL. 
 * @param new The new element to be added at the front of the list. Can be NULL.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/** Clears a linked list.
 * 
 * @param lst The first element of the list. Can be NULL.
 * @param del The function to delete the contents of the element. Can be NULL.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/** Deletes an element, without relinking the list.
 *
 * @param lst The element to be deleted. Can be NULL.
 * @param del The function to delete the contents of the element. Can be NULL.
 */
void	ft_lstdelone(t_list *restrict lst, void (*del)(void *));

/** Applies the function f to each element in the list. 
 *
 * @param lst The first element of the list. Can be NULL.
 * @param f The function to apply to each element. Can be NULL.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/** 
 * @param lst The first element of the list. Can be NULL.
 *
 * @returns The address of the last element in a given list. */
t_list	*ft_lstlast(t_list *lst);

/** Creates a copy of the list with the function f applied to each element.
 * 
 * @param lst The first element of the list. Can be NULL.
 *
 * @returns A pointer to the first element of the copy. 
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/** Creates a new t_list element.
 * 
 * @param content A pointer to any type of data. Can be NULL.
 *
 * @returns A pointer to the new element, or NULL if the allocation failed.
 */
t_list	*ft_lstnew(void *content);

/**
 * @param lst The first element of the list. Can be NULL.
 * 
 * @returns The numbers of elements in the list.
 */
int		ft_lstsize(t_list *lst);

/*
 * MATH functions 
 */

# ifndef INT_MAX
#  define INT_MAX	2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN	-2147483648
# endif

/** The ft_abs() function computes the absolute value of the integer i.
 *
 * @return The absolute value.
 */
int		ft_abs(int i);

// TODO
/* The fabs() functions compute the absolute value of a floating-point
 * number x.
 * @return The absolute value.
 */
int		ft_fabs(double x);
int		ft_fabsl(long double x);
int		ft_fabsf(float x);

// TODO
/** The ft_labs() functions compute the absolute value of a long number x.
 *
 * @return The absolute value.
 */
int		ft_labs(long i);

/* MEM functions */

/* The ft_bzero() function writes n zeroed bytes to the string s.
 * If n is zero, ft_bzero() does nothing. */
void	ft_bzero(void *s, size_t n);

/* The ft_calloc() function allocates enough space for count objects
 * that are size bytes of memory each and returns a pointer to the allocated
 * memory.  The allocated memory is filled with bytes of value zero. */
void	*ft_calloc(size_t count, size_t size);

/* The ft_memccpy() function copies bytes from string src to string dst. 
 * If the character c (converted to an unsigned char) occurs in the string
 * src, the copy stops and a pointer to the byte after the copy of c in the
 * string dst is returned. Otherwise, n bytes are copied, and a NULL pointer is
 * returned.
 *
 * The source and destination strings should not overlap,
 * as the behavior is undefined. */
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);

/* The ft_memchr() function locates the first occurrence of c
 * (as converted to an unsigned char) in the string s. */
void	*ft_memchr(const void *s, int c, size_t n);

/* The ft_memcmp() function compares byte string s1 against byte string s2.
 * Both strings are assumed to be n bytes long. */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* The memmove() function copies len bytes from string src to string dst.
 * The two strings may overlap; the copy is always done in a non-destructive
 * manner. */
void	*ft_memmove(void *dest, const void *src, size_t n);

/* The ft_memcpy() function copies n bytes from memory area src to memory
 * area dst. If dst and src overlap, behavior is undefined. Applications in
 * which dst and src might overlap should use ft_memmove instead. */
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);

/* The ft_memset() function writes len bytes of value c (converted to an
 * unsigned char) to the string b. */
void	*ft_memset(void *s, int c, size_t n);

/*
 * ft_printf 
 */

int		ft_dprintf(int fd, const char *restrict format, ...) \
	__attribute__((__format__ (__printf__, 2, 3)));
int		ft_printf(const char *restrict format, ...) \
	__attribute__((__format__ (__printf__, 1, 2)));

/*
 * STRING functions
 */

/* The ft_atoi() function converts the initial portion
 * of the string pointed by str to an int representation. */
int		ft_atoi(const char *str);

/* The ft_itoa() function converts an integer value to
 * a null-terminated string. */
char	*ft_itoa(int n);

/* Returns the length from s to the next character c
 * or the next '\\0' character. */
size_t	ft_len_to_char(const char *s, char c);

/* Returns the length from s to the next space character (using ft_isspace())
 * or the next '\\0' character. */
size_t	ft_len_to_space(const char *s);

/* The ft_str_tolower() function converts each uppercase letter to the 
 * corresponding lowercase letter in the null-terminated string s. */
void	ft_str_tolower(char *s);

/* The ft_str_toupper() function converts each lowercase letter to the 
 * corresponding uppercase letter in the null-terminated string s. */
void	ft_str_toupper(char *s);

/* 
 * The ft_strcmp() and ft_strncmp() functions lexicographically compare the
 * null-terminated strings s1 and s2.
 * 
 * @returns 0 if the strings are identical.
 */
int		ft_strcmp(const char *s1, const char *s2);

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
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* 
 * The ft_strdup() function allocates sufficient memory for a copy of the string
 * s1, does the copy, and returns a pointer to it. The pointer may subsequently
 * be used as an argument tothe function free(3).
 * 
 * If insufficient memory is available, NULL is returned.
 */
char	*ft_strdup(const char *s);

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
char	*ft_strndup(const char *s, size_t n);

/* 
 * The ft_strjoin() function appends the string s2 to the end of s1,
 * overwriting the terminating null character ('\\0') at the end of s1,
 * then adds a terminating null character.
 * 
 * If either of the strings is NULL, the function returns NULL.
 * 
 * Memory for the new string is obtained with malloc(3),
 * and can be freed with free(3);
 */
char	*ft_strjoin(const char *s1, const char *s2);

/* 
 * The ft_strjoin_3() function appends a copy of the null-terminated strings
 * s2 and s3 to the end of the null-terminated string s1, overwriting the
 * terminating null character ('\\0') at the end of s1, then adds a
 * terminating null character.
 * 
 * If one of the strings is NULL, the function returns NULL.
 * 
 * Memory for the new string is obtained with malloc(3),
 * and can be freed with free(3);
 */
char	*ft_strjoin_3(const char *s1, const char *s2, const char *s3);

/* 
 * The ft_strcat() and function append a copy of the null-terminated
 * string s2 to the end of the null-terminated string s1, then add a terminating
 * '\\0'. The string s1 must have sufficient space to hold the result.
 */
char	*ft_strcat(char *s1, const char *s2);

/* 
 * The ft_strcat() and function append a copy of the null-terminated
 * string s2 to the end of the null-terminated string s1, then add a terminating
 * '\\0'. The string s1 must have sufficient space to hold the result. 
 * 
 * The ft_strncat function appends not more than n characters from s2,
 * and then adds a terminating '\\0'.
 */
char	*ft_strncat(char *s1, const char *s2, size_t n);

/* 
 * The ft_strlcat() function appends the NUL-terminated
 * string src to the end of dst.
 * It will append at most size - ft_strlen(dst) - 1 bytes,
 * null-terminating the result.
 * 
 * The function returns the total length of the string it tried to create.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/* The ft_strcpy() function copy the string src to dst
 * (including the terminating '\\0' character.) */
char	*ft_strcpy(char *dest, const char *src);

/* 
 * The ft_strncpy() function copy the string src to dst
 * (including the terminating '\\0' character.)
 *
 * The function copy at most len characters from src into dst.
 * If src is less than n characters long, the remainder of dst is filled with
 * '\\0' characters. Otherwise, dst is not terminated.
 */
char	*ft_strncpy(char *s1, const char *s2, size_t n);

/* The ft_strlcpy() function copies up to size - 1 characters from
 * the NUL-terminated string src to dst, NUL-terminating the result. */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/* The ft_strlen() function computes the length of the string s. */
size_t	ft_strlen(const char *s);

/* The ft_strnlen() function attempts to compute the length of s,
 * but never scans beyond the first maxlen bytes of s. */
size_t	ft_strnlen(const char *s, size_t maxlen);

/* 
 * The ft_strnstr() function locates the first occurrence of the null-terminated
 * string needle in the string haystack, where not more than len characters are
 * searched. Characters that appear after a '\\0' character are not searched.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);

/* 
 * The ft_strchr() function locates the first occurrence of the char c in the
 * string pointed to by s. The terminating null character is considered to be
 * part of the string; therefore if c is '\\0', the function locates the
 * terminating '\\0'.
 * 
 * The function returns NULL if it cannot find the character c in the string s.
 */
char	*ft_strchr(const char *s, int c);

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
char	*ft_strrchr(const char *s, int c);

/* 
 * The ft_strmapi() applies the given function f to each character of the
 * string s to create a new string (with malloc(3))
 * resulting from successive applications of f.
 */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

/* 
 * The ft_substr() function allocates memory with malloc(3) then returns a
 * string of len characters (or up to the first '\\0' encountered), and starting
 * from index start of s.
 */
char	*ft_substr(char *s, unsigned int start, size_t len);

/*
 * The ft_strtrim() function allocates memory with malloc(3) then returns the
 * same string as s1, without the characters specified in set, at the start
 * and at the end of s1.
 */
char	*ft_strtrim(char *s1, char *set);

/*
 * WRITE functions
 */

/* Write a character on the standard output. */
void	ft_putchar(char c);

/* Write a character on the file descriptor fd. */
void	ft_putchar_fd(char c, int fd);

/* Print a number on the standard output. */
void	ft_putnbr(int n);

/* Print a number on the file descriptor fd. */
void	ft_putnbr_fd(int n, int fd);

/* Print the string s on the standard output. */
void	ft_putstr(const char *restrict s);

/* Print the string s on the file descriptor fd. */
void	ft_putstr_fd(const char *s, int fd);

/* Print the string s followed by a newline, on the standard output. */
void	ft_putendl(const char *restrict s);

/* Print a string followed by a newline, on the file descriptor fd. */
void	ft_putendl_fd(const char *s, int fd);

#endif /* !defined LIBFT_H */
