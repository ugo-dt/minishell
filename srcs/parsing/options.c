/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:14:52 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/28 22:15:15 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "cmd.h"

void	get_options(t_cmd *cmd)
{
	size_t	i;

	cmd->nb_options = 0;
	i = 1;
	while (i < cmd->nb_args)
	{
		if (cmd->args[i] && cmd->args[i][0] != '-')
			break ;
		cmd->nb_options++;
		i++;
	}
}
