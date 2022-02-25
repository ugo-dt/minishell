/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:51:31 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/02/25 22:46:45 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "shell.h"
#include "err.h"

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

int	count_words(char *line)
{
	t_uint	words;

	words = 0;
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
					line = pos_to_next_word(line);
				else
					line++;
		}
	}
	return (words);
}

int	check_quotes(char *line)
{
	char	looking_for_quote;

	looking_for_quote = 0;
	while (line && *line)
	{
		if (*line == '\'')
		{
			if (looking_for_quote == 0)
				looking_for_quote = '\'';
			else if (looking_for_quote == '\'')
				looking_for_quote = 0;
		}
		else if (*line == '\"')
		{
			if (looking_for_quote == 0)
				looking_for_quote = '\"';
			else if (looking_for_quote == '\"')
				looking_for_quote = 0;
		}
		line++;
	}
	if (looking_for_quote)
		ft_dprintf(STDERR_FILENO, "%s: %s: %s %c\n", SHELL_NAME, SYNTAX_ERROR,
			BAD_QUOTES_NEWLINE, looking_for_quote);
	return (0);
}

int	parse_command(t_cmd *cmd)
{
	//t_uint	i;

	if (!g_sh.line)
		return (0);
	if (check_quotes(g_sh.line) != 0)
		return (0);
	cmd->nb_words = count_words(g_sh.line);
	if (cmd->nb_words < 0)
		return (0);
	cmd->params = ft_xmalloc(sizeof(char *) * cmd->nb_words + 1);
	cmd->args = NULL;
	printf("words: %d\n", cmd->nb_words);
	return (1);
}
