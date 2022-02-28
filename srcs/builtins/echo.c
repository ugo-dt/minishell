/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:14:10 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/28 16:41:11 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	only_n(char *s)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static void	print_arguments(t_cmd *cmd)
{
	size_t	i;

	i = 1 + cmd->nb_options;
	while (i < cmd->nb_args)
	{
		ft_putstr(cmd->args[i++]);
		if (cmd->args[i])
			ft_putchar(' ');
	}
}

static char	print_options(t_cmd *cmd)
{
	size_t	i;
	char	c;
	char	n;

	i = 1;
	c = '\n';
	n = 1;
	while (cmd->args[i] && i < cmd->nb_options + 1)
	{
		if (cmd->args[i][0] != '-')
			break ;
		if (n && only_n(&cmd->args[i][1]))
			c = 0;
		else
		{
			n = 0;
			ft_printf("%s", cmd->args[i]);
			if (cmd->args[i + 1])
				ft_putchar(' ');
		}
		i++;
	}
	return (c);
}

int	echo(t_cmd *cmd)
{
	char	c;

	c = print_options(cmd);
	if (cmd->args[1])
		print_arguments(cmd);
	if (c)
		ft_putchar(c);
	return (EXIT_SUCCESS);
}
