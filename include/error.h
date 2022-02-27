/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:25:01 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/26 21:08:21 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "errno.h"

int		set_error_message(char *msg, char *info, int ret);
int		set_errno(char *name, char *info, int errnum, int ret);

/* ERROR_H */
#endif
