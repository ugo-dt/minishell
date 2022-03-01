/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:14:17 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/01 19:47:51 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "cmd.h"
# include <stdlib.h>

typedef struct s_pipe
{
	int		**pipe;
	size_t	nb_pipes;
	size_t	nb_cmd;
	pid_t	*pid;
	int		exit_status;
}t_pipe;

void	dup2_error(void);
void	init_pipes(t_pipe *p, t_cmd *cmd);
void	free_pipe(int **arr, size_t max);
void	close_pipes(t_pipe *p);

/* PIPE_H */
#endif
