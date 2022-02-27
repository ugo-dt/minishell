/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:21:13 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/27 21:56:58 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errno.h"
#include "error.h"
#include "shell.h"
#include "string.h"
#include "libft.h"

char	*get_error_message(void)
{
	if (g_sh.error_message == FATAL_ERROR)
		return ("critical error");
	if (g_sh.error_message == TOO_MANY_ARGS)
		return ("too many arguments");
	if (g_sh.error_message == NOT_ENOUGH_ARGS)
		return ("not enough arguments");
	if (g_sh.error_message == BAD_OPTION)
		return ("bad option");
	if (g_sh.error_message == HOME_NOT_SET)
		return ("HOME not set");
	if (g_sh.error_message == OLDPWD_NOT_SET)
		return ("OLDPWD not set");
	if (g_sh.error_message == CMD_NOT_FOUND)
		return ("command not found");
	if (g_sh.error_message == HOME_NOT_SET)
		return ("HOME not set");
	if (g_sh.error_message == HOME_NOT_SET)
		return ("HOME not set");
	if (g_sh.error_message == EXPORT_USAGE)
		return ("usage: export [name[=value]]");
	if (g_sh.error_message == UNSET_USAGE)
		return ("usage: unset [name]");
	if (g_sh.error_message == UNSET_USAGE)
		return ("not a valid identifier");
	return (NULL);
}

int	set_error_message(char *msg, char *info, int ret)
{
	ft_dprintf(STDERR_FILENO, "%s", SHELL_NAME);
	if (msg)
		ft_dprintf(STDERR_FILENO, ": %s", msg);
	if (info)
		ft_dprintf(STDERR_FILENO, ": %s", info);
	ft_dprintf(STDERR_FILENO, "\n");
	return (ret);
}

int	set_errno(char *name, char *info, int errnum, int ret)
{
	char	*s;

	ft_dprintf(STDERR_FILENO, "%s", SHELL_NAME);
	if (name)
		ft_dprintf(STDERR_FILENO, ": %s", name);
	if (info)
		ft_dprintf(STDERR_FILENO, ": %s", info);
	if (errnum > 0)
		errno = errnum;
	s = ft_strdup(strerror(errno));
	if (s)
	{
		ft_dprintf(STDERR_FILENO, ": %s", ft_lower(s));
		free(s);
	}
	else
		ft_dprintf(STDERR_FILENO, ": %s", strerror(errno));
	ft_dprintf(STDERR_FILENO, "\n");
	return (ret);
}
