/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:08:46 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/27 10:13:43 by ugdaniel         ###   ########.fr       */
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

/* SIG_H */
#endif
