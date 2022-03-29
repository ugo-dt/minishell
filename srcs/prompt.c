/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:11:07 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/29 15:29:03 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

char	*get_prompt(void)
{
	char	*ps1;

	if (g_sh.prompt)
		free(g_sh.prompt);
	ps1 = ft_getenv("PS1");
	//ft_printf("ps1: %s\n", ps1);
	return (ft_strdup(ps1));
}
