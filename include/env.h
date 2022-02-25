/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:55:37 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 17:30:21 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft.h"

typedef struct s_env_list
{
	char				*name;
	char				*value;
	int					export;
	struct s_env_list	*next;
}t_envl;

t_envl	*new_envl(const char *name, const char *value, int export, t_envl *next);
void	envl_delone(t_envl *envl);
void	clear_env_list(t_envl **start);
void	envl_pushback(t_envl **lst, t_envl *new);

int		ft_setenv(const char *name, const char *value, int replace);
char	*ft_getenv(const char *name);

/* ENV_H */
#endif