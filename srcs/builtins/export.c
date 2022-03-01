/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:53:43 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/01 13:05:13 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "error.h"

static void	sort_array(t_envl **array, size_t size)
{
	size_t	i;
	t_envl	*temp;

	i = -1;
	while (++i < size - 1)
	{
		if (ft_strcmp(array[i]->name, array[i + 1]->name) > 0)
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			i = -1;
		}
	}
	i = 0;
	while (i < size)
	{
		if (array[i]->name)
			ft_printf("declare -x %s=\"", array[i]->name);
		if (array[i]->value)
			ft_printf("%s", array[i]->value);
		ft_printf("\"\n");
		i++;
	}
}

int	no_arguments(void)
{
	t_envl	*e;
	t_envl	**array;
	size_t	i;
	size_t	size;

	size = 0;
	e = g_sh.envp;
	while (e)
	{
		if (ft_strcmp(e->name, "_") || ft_strlen(e->name) != 1)
			size++;
		e = e->next;
	}
	array = ft_xmalloc(sizeof(t_envl *) * size);
	e = g_sh.envp;
	i = 0;
	while (e)
	{
		if (ft_strcmp(e->name, "_") || ft_strlen(e->name) != 1)
			array[i++] = e;
		e = e->next;
	}
	sort_array(array, size);
	free(array);
	return (EXIT_SUCCESS);
}

int	export(t_cmd *cmd)
{
	size_t	i;

	if (cmd->args && !cmd->args[1])
		return (no_arguments());
	if (cmd->nb_options)
		return (show_error(BUILTIN_EXPORT_NAME, BAD_OPTION,
				cmd->args[1][1], EXPORT_USAGE));
	i = 1;
	while (i < cmd->nb_args)
	{
		if (ft_strchr(cmd->args[i], '?')
			|| ft_len_to_char(cmd->args[i], '=') < 1)
			ft_dprintf(g_sh.std_err, "%s: %s: '%s': %s\n", SHELL_NAME,
				BUILTIN_UNSET_NAME, cmd->args[i], INVALID_IDENTIFIER);
		else if (ft_strchr(cmd->args[i], '='))
			envl_pushback(&g_sh.envp, parse_env_line_to_envl(cmd->args[i]));
		i++;
	}
	return (EXIT_SUCCESS);
}
