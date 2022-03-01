/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:37:20 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/01 21:08:23 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "redirections.h"
# include <stdlib.h>

/* Command parsing structure
 * 
 * @param exec_name The first word is always the name of the executable
 * @param options String containing all of the options - starts with '-',
 * first word that does not is considered as an argument (you cannot have
 * options after arguments)
 * @param args Command arguments - always after the options
 * @param redir	Input/output redirection
 * @param fd_heredoc Heredoc pipe
 * @param next Next command connected with a pipe */
typedef struct s_command
{
	char				*exec_name;
	size_t				nb_options;
	char				**args;
	size_t				nb_args;
	t_redir				*redir;
	int					heredoc;
	int					fd_heredoc[2];
	struct s_command	*next;
}t_cmd;

t_cmd	*new_cmd(void);
size_t	nb_pipes(t_cmd *cmd);
void	clear_cmd(t_cmd *cmd);

size_t	nb_pipes(t_cmd *cmd);
size_t	nb_redir(t_cmd *cmd);

void	execute_cmd(t_cmd *cmd);
int		do_redirections(t_cmd *cmd);
void	find_file_in_path(t_cmd *cmd, char **path);

/* CMD_H */
#endif
