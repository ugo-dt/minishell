/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:11:07 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 16:11:21 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

char	*get_prompt(void)
{
	if (g_sh.prompt)
		free(g_sh.prompt);
	return (ft_strjoin(SHELL_NAME, "$ "));
}
