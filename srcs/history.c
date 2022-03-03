/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:17:53 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/03 14:58:22 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
#include "shell.h"

void	add_command_to_history(void)
{
	int		nb;
	t_hist	*temp;

	if (!g_sh.line || !ft_strlen(g_sh.line))
		return ;
	add_history(g_sh.line);
	temp = g_sh.history.cmd_hist;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		nb = temp->nb + 1;
		temp = NULL;
	}
	else
		nb = 1;
	ft_histaddback(&g_sh.history.cmd_hist,
		ft_histnew(g_sh.line, nb));
}
