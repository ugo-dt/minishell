/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:51:31 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 22:29:13 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "shell.h"

# define BAD_QUOTES	-1

char	*skip_quotes(char *start)
{
	char	q;

	q = *start;
	start++;
	while (start && *start && *start != q)
		start++;
	return (start);
}

char	*pos_to_next_word(char *s)
{
	while (*s && !ft_isspace(*s))
	{
		if (*s == '\'' || *s == '\"')
			s = skip_quotes(s);
		s++;
	}
	while (*s && ft_isspace(*s))
		s++;
	return (s);
}

int	count_words(void)
{
	t_uint	words;
	char	*line;

	words = 0;
	line = g_sh.line;
	while (*line)
	{
		if (*line == '\'' || *line == '\"')
		{
			words++;
			line = pos_to_next_word(line);
		}
		else if (ft_isspace(*line))
			line++;
		else
		{
			words++;
			while (*line && !ft_isspace(*line))
				if (*line == '\'' || *line == '\"')
					line = skip_quotes(line);
				else
					line++;
		}
	}
	return (words);
}

int	parse_command(t_cmd *cmd)
{
	//t_uint	i;

	if (!g_sh.line)
		return (0);
	cmd->nb_words = count_words();
	if (cmd->nb_words < 0)
		return (0);
	printf("words: %d\n", cmd->nb_words);
	return (1);
}
