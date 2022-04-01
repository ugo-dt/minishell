/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:08:46 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/04/01 19:52:43 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_H
# define SIG_H

# include "libft.h"
# include "prompt.h"
# include <signal.h>

void	sig_handler(int signum);
void	init_signals(void);
void	sig_execve_handler(int signum);

void	print_signal(const char **cmd, int status, int next, pid_t cpid);
char	*ft_strsignal(int num);

/* SIG_H */
#endif
