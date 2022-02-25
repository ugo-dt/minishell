/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:16:17 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 16:00:31 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "env.h"

# define SHELL_NAME			"minishell"

/* status flags */
# define FLAG				unsigned int
# define FLAG_INTERACTVE	0x00000001
# define FLAG_LOOP			0x00000002
# define FLAG_HISTORY		0x00000004

/* Exit codes */
# define EXIT_MISUSE			2
# define EXIT_CANT_EXECUTE		126
# define EXIT_NOT_FOUND			127
# define EXIT_NOT_RECOVERABLE	131
# define EXIT_OUT_OF_RANGE		255

typedef unsigned char		t_uchar;
typedef unsigned int		t_uint;
typedef unsigned long		t_ul;
typedef unsigned long long	t_ull;

typedef struct g_shell
{
	FLAG	status;
	char	*current_dir;
	t_envl	*envp;
	char	**path;
	char	*line;
	char	*prompt;
	t_uchar	exit_value;
	char	*error_message;
}t_shell;

extern t_shell				g_sh;

/* SHELL_H */
#endif