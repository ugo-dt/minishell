/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:21:13 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/28 13:02:43 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "shell.h"
#include "string.h"
#include "libft.h"
#include <errno.h>

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

void	*set_errno_ptr(char *name, char *info, int errnum, void *ret)
{
	set_errno(name, info, errnum, EXIT_FAILURE);
	return (ret);
}
