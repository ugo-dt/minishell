/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:21:13 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/03 15:12:08 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "shell.h"
#include "string.h"
#include "libft.h"
#include <errno.h>

int	set_error_message(char *msg, char *info, int ret)
{
	ft_dprintf(g_sh.std_err, "%s", SHELL_NAME);
	if (msg)
		ft_dprintf(g_sh.std_err, ": %s", msg);
	if (info)
		ft_dprintf(g_sh.std_err, ": %s", info);
	ft_dprintf(g_sh.std_err, "\n");
	return (ret);
}

int	set_errno(char *name, char *info, int errnum, int ret)
{
	ft_dprintf(g_sh.std_err, "%s", SHELL_NAME);
	if (name)
		ft_dprintf(g_sh.std_err, ": %s", name);
	if (info)
		ft_dprintf(g_sh.std_err, ": %s", info);
	if (errnum > 0)
		errno = errnum;
	ft_dprintf(g_sh.std_err, ": %s\n", strerror(errno));
	return (ret);
}

void	*set_errno_ptr(char *name, char *info, int errnum, void *ret)
{
	set_errno(name, info, errnum, EXIT_FAILURE);
	return (ret);
}
