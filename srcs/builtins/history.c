/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:43:33 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/28 13:10:56 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	print_spaces(int n)
{
	if (n <= 9)
		ft_putstr("    ");
	else if (n > 9 && n <= 99)
		ft_putstr("   ");
	else if (n > 99 && n <= 999)
		ft_putstr("  ");
	else if (n > 999 && n <= 9999)
		ft_putchar(' ');
}

int	print_history(void)
{
	t_hist	*temp;

	temp = g_sh.history.cmd_hist;
	while (temp)
	{
		if (temp->line)
		{
			print_spaces(temp->nb);
			ft_putnbr(temp->nb);
			ft_putstr("  ");
			ft_putstr(temp->line);
			ft_putchar('\n');
		}
		temp = temp->next;
	}
	return (EXIT_SUCCESS);
}
