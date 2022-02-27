/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:25:01 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/27 21:55:57 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "errno.h"

# define FATAL_ERROR				0x00000001
# define TOO_MANY_ARGS				0x00000002
# define NOT_ENOUGH_ARGS			0x00000004
# define BAD_OPTION					0x00000004
# define EXIT_NUM_ARG_REQUIRED		0x00000008
# define HOME_NOT_SET				0x00000016
# define OLDPWD_NOT_SET				0x00000032
# define CMD_NOT_FOUND				0x00000064
# define EXPORT_USAGE				0x00000128
# define UNSET_USAGE				0x00000256
# define INVALID_IDENTIFIER			0x00000512

char	*get_error_message(void);
int		set_error_message(char *msg, char *info, int ret);
int		set_errno(char *name, char *info, int errnum, int ret);

/* ERROR_H */
#endif
