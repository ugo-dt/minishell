/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:21:13 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 17:28:40 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errno.h"
#include "shell.h"
#include "string.h"

int	set_errno(int errnum, int ret)
{
	errno = errnum;
	g_sh.error_message = ft_strdup(strerror(errno));
	return (ret);
}
