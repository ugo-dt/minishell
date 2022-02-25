/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:33:19 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/06 12:56:45 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The following functions make use of */

#ifndef _FT_LIST_H
# define _FT_LIST_H	1

# if !defined _LIBFT_HEADER
#  error "Do not include "_ft_list.h" directly. Use "libft.h" instead."
# endif

# include <stdlib.h>

/*
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

/* Adds a new element at the end of the list. */
extern void		ft_lstadd_back(t_list **lst, t_list *new);

/* Adds a new element at the start of the list. */
extern void		ft_lstadd_front(t_list **lst, t_list *new);

/* Clears the list.
 * @param lst first element of the list to be deleted;
 * @param del appropriate function to delete the contents of the element. */
extern void		ft_lstclear(t_list **lst, void (*del)(void *));

/* Deletes an element, without relinking the list.
 * @param lst element to be deleted;
 * @param del appropriate function to delete the contents of the element. */
extern void		ft_lstdelone(t_list *lst, void (*del)(void *));

/* Applies the function f to each element in the list. */
extern void		ft_lstiter(t_list *lst, void (*f)(void *));

/* Returns the address of the last element in a given list. */
extern t_list	*ft_lstlast(t_list *lst);

/* Creates a copy of the list with the function f applied to each element. */
extern t_list	*ft_lstmap(t_list *lst,
					void *(*f)(void *),
					void (*del)(void *));

/* Creates a new element. */
extern t_list	*ft_lstnew(void *content);

/* Returns the numbers of elements in a list. */
extern int		ft_lstsize(t_list *lst);

/* _FT_LIST_H */
#endif
