/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:11:15 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 22:02:30 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "libft.h"
# include "shell.h"
# include <stdlib.h>

/* cd builtin
 *
 * No options, absolute or relative path. */
int				cd(t_cmd *cmd);

/* echo builtin
 *
 * '-n' option is available. */
int				echo(t_cmd *cmd);

/* env builtin
 *
 * No options nor arguments. */
int				env(void);

/* export builtin
 *
 * No options. */
int				export(t_cmd *cmd);

/* unset builtin
 *
 * No options. */
int				unset(t_cmd *cmd);

/* pwd builtin
 *
 * No options nor arguments. */
int				pwd(t_cmd *cmd);

/* exit builtin
 *
 * No options. */
int				run_exit(t_cmd *cmd);

/* BUILTIN */
#endif
