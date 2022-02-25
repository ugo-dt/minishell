/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 08:43:37 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/18 15:37:05 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "_ft_array.h"

void	ft_sort_array(char **array)
{
	int		i;
	char	*temp;

	i = 0;
	while (array[i + 1])
	{
		if (ft_strcmp(array[i], array[i + 1]) > 0)
		{
			temp = ft_strdup(array[i]);
			free(array[i]);
			array[i] = ft_strdup(array[i + 1]);
			free(array[i + 1]);
			array[i + 1] = ft_strdup(temp);
			free(temp);
			i = 0;
		}
		else
			i++;
	}
}

char	**ft_copy_array(char **arr)
{
	size_t	i;
	size_t	size;
	char	**copy;

	size = ft_array_size((void **)arr);
	copy = malloc(sizeof(char *) * (size + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (arr[i] && i < size)
	{
		copy[i] = ft_strdup(arr[i]);
		if (!copy[i])
		{
			ft_free_array_n((void **)copy, i);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
