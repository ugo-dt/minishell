/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:53:52 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/03 16:23:49 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "cmd.h"

int		heredoc(t_cmd *cmd, char *delim, int quoted);
int		do_heredocs(t_cmd *cmd);
int		do_heredocs_builtin(t_cmd *cmd);

/* HEREDOC_H */
#endif
