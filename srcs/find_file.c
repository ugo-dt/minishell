/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:04:47 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/01 22:04:12 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "libft.h"
#include <sys/stat.h>

void	find_file_in_path(t_cmd *cmd, char **path)
{
	int			i;
	char		*temp;
	char		*dst;
	struct stat	buffer;

	if (!path || !(*path) || !cmd || !cmd->exec_name
		|| ft_strchr(cmd->exec_name, '/'))
		return ;
	temp = ft_strjoin("/", cmd->exec_name);
	i = 0;
	while (path[i] && temp)
	{
		dst = ft_strjoin(path[i], temp);
		if ((stat(dst, &buffer) == 0))
		{
			cmd->exec_name = dst;
			break ;
		}
		free(dst);
		i++;
	}
	free(temp);
}
