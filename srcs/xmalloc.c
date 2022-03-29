/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:09:01 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/29 12:12:55 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xmalloc.h"

void	*ft_xmalloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
	{
		ft_dprintf(STDERR_FILENO,
			"\ncould not allocate %lu bytes: no memory available\n", size);
		exit(1);
	}
	return (ret);
}
