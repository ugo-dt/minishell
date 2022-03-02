/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:11:15 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/02 16:44:40 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "libft.h"
# include "shell.h"
# include "parser.h"
# include <stdlib.h>

/* Builtin commands */
# define BUILTIN_ECHO_NAME		"echo"
# define BUILTIN_CD_NAME		"cd"
# define BUILTIN_PWD_NAME		"pwd"
# define BUILTIN_EXPORT_NAME	"export"
# define BUILTIN_UNSET_NAME		"unset"
# define BUILTIN_ENV_NAME		"env"
# define BUILTIN_EXIT_NAME		"exit"
# define BUILTIN_HISTORY_NAME	"history"

# define BUILTIN_ECHO			1
# define BUILTIN_CD				2
# define BUILTIN_PWD			3
# define BUILTIN_EXPORT			4
# define BUILTIN_UNSET			5
# define BUILTIN_ENV			6
# define BUILTIN_HISTORY		7
# define BUILTIN_EXIT			8

/* cd builtin
 *
 * 'cd [path]'
 * 'cd -' */
int				cd(t_cmd *cmd);

static inline int	can_copy(char **comp, unsigned int *i)
{
	if (ft_strcmp(comp[*i], ".") == 0 && ft_strlen(comp[*i]) == 1)
		return (0);
	if ((ft_strcmp(comp[*i], "..") != 0 || ft_strlen(comp[*i]) != 2)
		&& comp[*i + 1]
		&& ft_strcmp(comp[*i + 1], "..") == 0 && ft_strlen(comp[*i + 1]) == 2)
	{
		(*i)++;
		return (0);
	}
	return (1);
}

/* echo builtin
 *
 * 'echo [-n] [arg]*' */
int				echo(t_cmd *cmd);

/* env builtin
 *
 * 'env' */
int				env(t_cmd *cmd);

/* export builtin
 *
 * 'export [name[=value]]' */
int				export(t_cmd *cmd);

/* unset builtin
 *
 * 'unset <name>' */
int				unset(t_cmd *cmd);

/* pwd builtin
 *
 * 'pwd' */
int				pwd(t_cmd *cmd);

/* exit builtin
 *
 * 'exit [status]' */
int				run_exit(t_cmd *cmd);

int				show_error(char *name, char *err, char option, char *usage);
int				unrecognized_option(char *name, char *option, char *usage);
int				find_builtin(t_cmd *cmd);
int				run_builtin(t_cmd *cmd, int builtin);
int				try_builtin_first(t_cmd *cmd);

size_t			do_builtin_redirections(t_cmd *cmd, t_redir *r);
void			close_builtin_redirections(t_cmd *cmd, size_t count);

/* BUILTIN */
#endif
