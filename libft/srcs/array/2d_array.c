/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:26:05 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/18 15:36:39 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "_ft_array.h"

size_t	ft_array_size(void **arr)
{
	size_t	i;

	if (!arr || !(*arr))
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_free_array(void **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	ft_free_array_n(void **tab, size_t max)
{
	size_t	i;

	i = 0;
	while (i < max)
		free(tab[i++]);
	free(tab);
}

void	ft_print_array_fd(const char **arr, int fd)
{
	int		i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		ft_putendl_fd(arr[i++], fd);
}
