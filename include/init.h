/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:08:18 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 15:02:30 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "env.h"
# include "libft.h"
# include "shell.h"

void	init_env(const char **envp);

extern t_shell	g_sh;

/* INIT_H */
#endif
