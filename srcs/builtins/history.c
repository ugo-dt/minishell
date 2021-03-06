/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:43:33 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/03 17:45:47 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "shell.h"

static void	print_spaces(int n)
{
	if (n <= 9)
		ft_putstr_fd("    ", g_sh.std_out);
	else if (n > 9 && n <= 99)
		ft_putstr_fd("   ", g_sh.std_out);
	else if (n > 99 && n <= 999)
		ft_putstr_fd("  ", g_sh.std_out);
	else if (n > 999 && n <= 9999)
		ft_putchar_fd(' ', g_sh.std_out);
}

int	print_history(void)
{
	t_hist	*temp;

	temp = g_sh.history.cmd_hist;
	if (!temp)
		return (EXIT_FAILURE);
	while (temp)
	{
		if (temp->line)
		{
			print_spaces(temp->nb);
			ft_putnbr_fd(temp->nb, g_sh.std_out);
			ft_putstr_fd("  ", g_sh.std_out);
			ft_putendl_fd(temp->line, g_sh.std_out);
		}
		temp = temp->next;
	}
	return (EXIT_SUCCESS);
}
