/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:14:50 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 19:24:22 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include <stdio.h>
# include <readline/history.h>

/* History command structure
 * 
 * See struct struct s_history for more info */
typedef struct s_hist
{
	char			*line;
	int				nb;
	struct s_hist	*next;
}t_hist;

/*
 *	History handler structure
 *
 * @param max_size The number of lines or commands that are stored in memory
 * in a history list while the session is ongoing. Can be modified in .mshrc
 * with HISTSIZE.
 * @param cmd_hist Linked list with all the commands sent by the user during
 * the session. Reads and stores the commands in the history file at the start
 * of each session.
 */
typedef struct s_history
{
	int		max_size;
	t_hist	*cmd_hist;
}t_history;

int		ft_histsize(t_hist *lst);
void	ft_histdelone(t_hist *lst);
void	ft_histaddback(t_hist **lst, t_hist *new);
t_hist	*ft_histnew(void *line, int nb);

int		init_history(void);
void	add_command_to_history(void);
int		print_history(void);
void	clear_history(void);

/* HISTORY_H */
#endif
