/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:11:15 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/28 20:31:13 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "libft.h"
# include "shell.h"
# include "parser.h"
# include <stdlib.h>

/* Builtin commands */
# define BUILTIN_ECHO		"echo"
# define BUILTIN_CD			"cd"
# define BUILTIN_PWD		"pwd"
# define BUILTIN_EXPORT		"export"
# define BUILTIN_UNSET		"unset"
# define BUILTIN_ENV		"env"
# define BUILTIN_EXIT		"exit"
# define BUILTIN_HISTORY	"history"

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
int				try_builtin_first(t_cmd *cmd);

/* BUILTIN */
#endif
