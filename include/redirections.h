/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:45:08 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/01 13:10:42 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

# include <stdlib.h>

# define IO_FILE_IN			0
# define IO_FILE_OUT		1
# define IO_FILE_APPEND		2
# define IO_HEREDOC			3

/* Redirections
 *
 * @param file File to redirect to/from
 * @param mode Redirection mode (input, output, append, delimiter)
 * @param next Next redirection. */
typedef struct s_redirection
{
	char					*file;
	int						mode;
	struct s_redirection	*next;
}t_redir;

t_redir	*new_redirection(const char *file, size_t size, unsigned int type);
void	free_redir(t_redir *redir);
void	ft_rediraddback(t_redir **lst, t_redir *new);

/* REDIRECTIONS_H */
#endif
