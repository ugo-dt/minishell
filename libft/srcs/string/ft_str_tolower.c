/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:23:31 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/09/28 15:23:31 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_tolower(char *s)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		if (ft_isupper(s[i]))
			s[i] = (char)ft_tolower(s[i]);
		i++;
	}
}
