# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 13:39:06 by ugdaniel          #+#    #+#              #
#    Updated: 2022/03/01 21:25:26 by ugdaniel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	minishell

SRCS			:=	srcs/main.c \
					srcs/builtin_redirections.c \
					srcs/cmd.c \
					srcs/error.c \
					srcs/execute_cmd.c \
					srcs/find_builtin.c \
					srcs/find_file.c \
					srcs/heredoc.c \
					srcs/history.c \
					srcs/history_struct.c \
					srcs/init.c \
					srcs/parse_command.c \
					srcs/prompt.c \
					srcs/redirections.c \
					srcs/signal.c \
					srcs/builtins/cd.c \
					srcs/builtins/echo.c \
					srcs/builtins/env.c \
					srcs/builtins/exit.c \
					srcs/builtins/export.c \
					srcs/builtins/heredoc_builtin.c \
					srcs/builtins/history.c \
					srcs/builtins/pwd.c \
					srcs/builtins/unset.c \
					srcs/parsing/checks.c \
					srcs/parsing/lexer.c \
					srcs/parsing/options.c \
					srcs/parsing/parameter_expansion.c \
					srcs/parsing/parser.c \
					srcs/parsing/quotes.c \
					srcs/parsing/redirections.c \
					srcs/parsing/tokens.c \
					srcs/parsing/word.c \
					srcs/variables/env.c \
					srcs/variables/ft_getenv.c \
					srcs/variables/ft_setenv.c \
					srcs/variables/ft_unsetenv.c

OBJS			:= 	$(SRCS:.c=.o)

LIBS			:=	-lreadline
PATH_LIBFT		:=	libft
LIBFT			:=	$(PATH_LIBFT)/libft.a

LIBFT_HEADERS	:=	-I $(PATH_LIBFT)/include
HEADERS			:= 	-I include \
					$(LIBFT_HEADERS)

CC				:=	clang
CFLAGS			:=	-Wall -Werror -Wextra $(MACROS) -fsanitize=address -DDEBUG

ARG				:=	-DARG_MAX=$(shell getconf ARG_MAX)
ifeq ($(OS), Linux)
MACROS			:=	$(ARG) -DLINUX
else
MACROS			:=	$(ARG)
endif

# Colors
DEFAULT			:=	\033[39m
GREEN			:=	\033[92m
MAGENTA			:=	\033[95m
RED				:=	\033[91m

all: $(NAME)

$(NAME): $(LIBFT) text1 $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) ready!$(DEFAULT)"

.c.o:
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	@make -C $(PATH_LIBFT)

clean_libft:
	@make -s -C $(PATH_LIBFT) clean

clean: clean_libft
	@echo "$(MAGENTA)Removed object files $(DEFAULT)"
	@rm -rf $(OBJS)

fclean: clean
	@make -s -C $(PATH_LIBFT) fclean
	@rm -rf $(NAME)
	@echo "$(RED)Removed $(NAME)$(DEFAULT)"

re: fclean newline all

newline:
	@printf "$(DEFAULT)\n"

text1:
	@echo "$(DEFAULT)Compiling $(NAME)... \t"

.PHONY: all clean_libft clean fclean newline text1 re
