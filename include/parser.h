/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:59:37 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/03/30 18:13:04 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cmd.h"
# include "libft.h"
# include "redirections.h"
# include "shell.h"

# define BAD_QUOTES_NEWLINE	"unexpected newline while looking for matching"

# define NO_TOKEN			0
# define TOKEN_NEWLINE		1
# define TOKEN_GREAT		2
# define TOKEN_LESS			3
# define TOKEN_GREATGREAT	4
# define TOKEN_LESSLESS		5
# define TOKEN_PIPE			6
# define TOKEN_WORD			7
# define TOKEN_COLON		8

# define TOKEN				unsigned int

/* Token
 * 
 * The Lexical analyzer separates input into tokens.
 * It will read the characters one by one from the standard input,
 * and form a token that will be passed to the parser.
 * 
 * @param type	The token type (operator/word)
 * @param word	If the token is not an operator, 'word' is the word
 * @param wsize	Size of the word (if token is not an operator */
typedef struct s_token
{
	TOKEN			type;
	char			*word;
	size_t			wsize;
	char			quoted;
	int				expand;
	struct s_token	*next;
}t_token;

t_token				*new_token(TOKEN t, const char *word, size_t size);
size_t				size_tokenlist(t_token *lst);
void				clear_tokenlist(t_token **t);
void				tokenlist_add_back(t_token **lst, t_token *new);
void				change_last_token_type(t_token **lst, TOKEN type);

static inline int	is_token_separator(char c)
{
	return (!c || c == '#' || c == '\n' || c == '<' || c == '>' || c == '|'
		|| ft_isspace(c));
}

static inline int	is_env_separator(char c)
{
	return (is_token_separator(c) || c == '$');
}

/* parser */
int					check_token_order(t_token **list);
char				*expand_param(const char *str,
						size_t strsize, uint32_t type);
char				*expand(char **dest, size_t i, int dquoted, char *temp);

/* Minishell lexer: token recognition
 *
 * cmd [arg]* [| cmd [arg]* ]*
 *  [[> filename] [< filename] [>> filename] [<< 'heredoc limit']
 * 
 * Read each character from the input line one by one.
 * 	1. If the end of input is recognized, the current token shall be delimited.
 * 
 * 	2. If the previous character was used as part of an operator and the current
 * 		character is not quoted and can be used with the current characters to
 * 		form an operator, it shall be used as part of that (operator) token.
 * 
 * 	3. If the previous character was used as part of an operator and the current
 * 		character cannot be used with the current characters to form an operator,
 * 		the operator containing the previous character shall be delimited
 * 
 * 	4. If the current character is single-quote or double-quote and it is not
 * 		quoted, it shall affect quoting for subsequent characters up to the
 * 		end of the quoted text.
 * 
 *	5. If the current character is an unquoted <newline>, the current token
 * 		shall be delimited.
 * 
 *	6. If the previous character was part of a word, the current character
 *		shall be appended to that word.
 * 
 * 	7. If the current character is an unquoted <blank>, any token containing
 * 		the previous character is delimited and the current character shall
 * 		be discarded.
 * 
 * 	8. If the current character is an unquoted '#', it and all subsequent
 * 		characters shall be discarded as a comment.
 * 
 * 	9. The current character is used as the start of a new word. */
t_token				*lexer(const char *line, size_t i);

/* quotes */
char				*remove_quotes(char *str);

static inline char	*quote_type(char q)
{
	if (q == '\'')
		return ("'");
	return ("\"");
}

void				start_to_parse_command(void);;
int					parse_command(t_cmd *cmd, const char *line);
t_cmd				*new_cmd(void);

void				get_options(t_cmd *cmd);

int					check_quotes(const char *line);

size_t				word_len(const char *word);
void				lexer_word(const char *line, size_t *i, t_token **list);

/* PARSER_H */
#endif 
