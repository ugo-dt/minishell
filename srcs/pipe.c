/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:43:04 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/01 22:50:56 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"
#include "cmd.h"
#include "libft.h"
#include "shell.h"

void	init_pipes(t_pipe *p, size_t nb_pipes)
{
	size_t	i;

	p->nb_cmd = nb_pipes + 1;
	p->nb_pipes = nb_pipes;
	p->pid = ft_xmalloc(sizeof(pid_t) * p->nb_cmd);
	p->pipe = ft_xmalloc(sizeof(int *) * p->nb_pipes);
	i = 0;
	while (i < p->nb_pipes)
		p->pipe[i++] = ft_xmalloc(sizeof(int) * 2);
	i = 0;
	while (i < p->nb_pipes)
	{
		if ((pipe(p->pipe[i++]) < 0))
		{
			ft_putstr_fd(SHELL_NAME, STDERR_FILENO);
			ft_putstr_fd(": ", STDERR_FILENO);
			perror("pipe");
			exit(EXIT_FAILURE);
		}
	}
}

void	free_pipe(int **arr, size_t max)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (i < max)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
}

void	close_pipes(t_pipe *p)
{
	size_t	i;

	i = 0;
	while (i < p->nb_pipes)
	{
		close(p->pipe[i][0]);
		close(p->pipe[i][1]);
		i++;
	}
}
