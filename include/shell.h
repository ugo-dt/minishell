/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:16:17 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/01 13:17:14 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "env.h"
# include "history.h"
# include "termios.h"

typedef unsigned char			t_uchar;
typedef unsigned int			t_uint;
typedef unsigned long			t_ul;
typedef unsigned long long		t_ull;

# define SHELL_NAME				"minishell"

/* status flags */
# define FLAG					unsigned int
# define FLAG_INTERACTVE		0x00000001
# define FLAG_LOOP				0x00000002
# define FLAG_HISTORY			0x00000004

/* Exit codes */
# define EXIT_NOT_FOUND			127
# define EXIT_OUT_OF_RANGE		255

typedef struct g_shell
{
	FLAG			status;
	t_envl			*envp;
	char			*line;
	char			*prompt;
	t_uchar			exit_value;
	t_uint			error_message;
	t_history		history;
	int				std_out;
	int				std_in;
	int				std_err;
	struct termios	termios_save;
}t_shell;

extern t_shell					g_sh;

/* SHELL_H */
#endif
