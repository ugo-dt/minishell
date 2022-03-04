/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:56:32 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/04 17:43:23 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "_ft_mem.h"

static void	ft_xmalloc_failed(size_t size)
{
	ft_dprintf(STDERR_FILENO, "\nout of memory allocating %lu bytes\n", size);
	exit(EXIT_FAILURE);
}

void	*ft_xmalloc(size_t size)
{
	char	*ret;

	ret = malloc(size);
	if (!ret)
		ft_xmalloc_failed(size);
	return (ret);
}
