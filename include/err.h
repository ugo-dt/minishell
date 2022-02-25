/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:25:01 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 22:43:48 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_H
# define ERR_H

# include "errno.h"

# define SYNTAX_ERROR		"syntax error"
# define BAD_QUOTES_NEWLINE	"unexpected newline while looking for matching"

int	set_errno(int errnum, int ret);

/* ERR_H */
#endif
