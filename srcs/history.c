/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:17:53 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/02 16:13:17 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
#include "shell.h"

void	add_command_to_history(void)
{
	t_hist	*temp;

	if (!g_sh.line || !ft_strlen(g_sh.line))
		return ;
	add_history(g_sh.line);
	if (!g_sh.history.cmd_hist)
	{
		g_sh.history.cmd_hist = ft_histnew(g_sh.line, 1);
		return ;
	}
	temp = g_sh.history.cmd_hist;
	while (temp->next)
		temp = temp->next;
	ft_histaddback(&g_sh.history.cmd_hist,
		ft_histnew(g_sh.line, temp->nb + 1));
}
