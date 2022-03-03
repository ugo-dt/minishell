/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:53:43 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/03 17:45:00 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "errors.h"

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

static int	set_env_from_line(const char *line)
{
	size_t	i;
	char	*name;
	char	*value;

	i = 0;
	while (line[i] && line[i] != '=')
		i++;
	name = ft_strndup(line, i + 1);
	if (!name)
		return (set_errno(BUILTIN_EXPORT_NAME,
				"could not export new variable", ENOMEM, 0));
	name[i] = '\0';
	i++;
	value = ft_strdup(&line[i]);
	if (!value)
	{
		free(name);
		return (set_errno(BUILTIN_EXPORT_NAME,
				"could not export new variable", ENOMEM, 0));
	}
	ft_setenv(name, value, 1);
	free(name);
	free(value);
	return (1);
}

int	export(t_cmd *cmd)
{
	int		done;
	size_t	i;

	if (cmd->args && !cmd->args[1])
		return (no_arguments());
	if (cmd->nb_options)
		return (show_error(BUILTIN_EXPORT_NAME, BAD_OPTION,
				cmd->args[1][1], EXPORT_USAGE));
	i = 1;
	done = 0;
	while (i < cmd->nb_args)
	{
		if (ft_strchr(cmd->args[i], '?')
			|| ft_len_to_char(cmd->args[i], '=') < 1)
		{
			ft_dprintf(g_sh.std_err, "%s: %s: '%s': %s\n", SHELL_NAME,
				BUILTIN_EXPORT_NAME, cmd->args[i], INVALID_IDENTIFIER);
			done = 1;
		}
		else if (ft_strchr(cmd->args[i], '='))
			if (!set_env_from_line(cmd->args[i]))
				done = 1;
		i++;
	}
	return (done);
}
