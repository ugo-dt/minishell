/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:08:46 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 15:54:22 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

# include "libft.h"
# include "prompt.h"
# include <signal.h>

void	sig_handler(int signum);
void	init_signals(void);

/* SIGNAL_H */
#endif
