/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:18:58 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/03 16:59:32 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
#include "shell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	ft_histdelone(t_hist *lst)
{
	if (lst)
	{
		if (lst->line)
			free(lst->line);
		lst->line = NULL;
		free(lst);
		lst = NULL;
	}
}

void	clear_history(void)
{
	t_hist	*temp;

	rl_clear_history();
	while (g_sh.history.cmd_hist)
	{
		temp = g_sh.history.cmd_hist;
		g_sh.history.cmd_hist = g_sh.history.cmd_hist->next;
		ft_histdelone(temp);
	}
}

t_hist	*ft_histnew(void *line, int nb)
{
	t_hist	*elem;

	elem = ft_xmalloc(sizeof(*elem));
	elem->line = ft_strdup(line);
	elem->next = NULL;
	elem->nb = nb;
	return (elem);
}

void	ft_histaddback(t_hist **lst, t_hist *new)
{
	t_hist	*temp;

	temp = *lst;
	if (temp == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

int	ft_histsize(t_hist *lst)
{
	int		size;
	t_hist	*temp;

	size = 0;
	temp = lst;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}
