/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:57:23 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/04 18:01:21 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "errors.h"
#include <errno.h>

static char	*get_env_name(char *str)
{
	size_t	size;
	char	*env;

	env = NULL;
	size = 0;
	while (str[size] && str[size] != '$'
		&& str[size] != '\'' && str[size] != '\"'
		&& !is_env_separator(str[size]))
		size++;
	env = ft_xmalloc(sizeof(char) * size + 1);
	ft_memset(env, 0, size + 1);
	ft_strncat(env, str, size);
	env[size] = '\0';
	if (!env)
		return (NULL);
	return (env);
}

static char	*get_env_value(char *env_name)
{
	char	*get;

	if (ft_strcmp(env_name, "?") == 0 && ft_strlen(env_name) == 1)
		return (ft_itoa(g_sh.exit_value));
	get = ft_getenv(env_name);
	if (!get)
		return (ft_strdup("\0"));
	return (ft_strdup(get));
}

char	*join(char *old, size_t env_start, char *env_name)
{
	size_t	i;
	size_t	j;
	char	*env_value;
	char	*dst;

	env_value = get_env_value(env_name);
	if (!env_value)
		exit(set_errno("error", NULL, ENOMEM, EXIT_FAILURE));
	dst = ft_xmalloc(sizeof(char) * ft_strlen(old) + ft_strlen(env_value) + 1);
	i = 0;
	while (i < env_start - 1)
	{
		dst[i] = old[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(env_value))
		dst[i++] = env_value[j++];
	j = env_start + ft_strlen(env_name);
	while (old[j])
		dst[i++] = old[j++];
	dst[i] = '\0';
	free(env_name);
	free(env_value);
	return (dst);
}

char	*expand(char **dest, size_t i, int dquoted, char *temp)
{
	while ((*dest)[i])
	{
		if ((*dest)[i] == '\"')
		{
			if (!dquoted)
				dquoted = 1;
			else
				dquoted = 0;
			i++;
		}
		if ((*dest)[i] == '\'' && !dquoted)
			i += word_len(&(*dest)[i]);
		else if ((*dest)[i] == '$')
		{
			temp = join((*dest), i + 1, get_env_name(&(*dest)[i + 1]));
			free((*dest));
			(*dest) = temp;
			i = 0;
			if (dquoted)
				dquoted = 0;
		}
		else if ((*dest)[i])
			i++;
	}
	return ((*dest));
}

char	*expand_param(const char *str, size_t strsize, uint32_t type)
{
	char	*dest;

	dest = ft_strndup(str, strsize + 1);
	dest[strsize] = '\0';
	if (type == TOKEN_LESSLESS)
		return (dest);
	dest = expand(&dest, 0, 0, NULL);
	return (remove_quotes(dest));
}
