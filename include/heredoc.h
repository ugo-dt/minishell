/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:53:52 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/02 16:48:56 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "cmd.h"

int		heredoc(t_cmd *cmd, char *delim);
int		do_heredocs(t_cmd *cmd);
int		do_heredocs_builtin(t_cmd *cmd);

/* HEREDOC_H */
#endif
