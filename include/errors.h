/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:38:24 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/03 17:38:31 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <errno.h>

# define FATAL_ERROR				"critical error"
# define TOO_MANY_ARGS				"too many arguments"
# define NOT_ENOUGH_ARGS			"not enough arguments"
# define BAD_OPTION					"bad option"
# define EXIT_NUM_ARG_REQUIRED		"numeric argument required"
# define HOME_NOT_SET				"HOME not set"
# define OLDPWD_NOT_SET				"OLDPWD not set"
# define CMD_NOT_FOUND				"command not found"
# define EXPORT_USAGE				"usage: export [name[=value]]"
# define UNSET_USAGE				"usage: unset [name]"
# define INVALID_IDENTIFIER			"not a valid indentifier"

int		set_error_message(char *msg, char *info, int ret);
int		set_errno(char *name, char *info, int errnum, int ret);
void	*set_errno_ptr(char *name, char *info, int errnum, void *ret);

/* ERRORS_H */
#endif
