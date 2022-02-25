# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@42.student.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 13:39:06 by ugdaniel          #+#    #+#              #
#    Updated: 2022/02/25 15:53:40 by ugdaniel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	minishell

SRCS			:=	srcs/init.c srcs/main.c srcs/prompt.c srcs/signal.c \
					srcs/builtins/export.c \
					srcs/parsing/parsing.c \
					srcs/variables/env.c
OBJS			:= 	$(SRCS:.c=.o)

LIBS			:=	-lreadline
PATH_LIBFT		:=	libft
LIBFT			:=	$(PATH_LIBFT)/libft.a

LIBFT_HEADERS	:=	-I $(PATH_LIBFT)/include
HEADERS			:= 	-I include \
					$(LIBFT_HEADERS)

CC				:=	@clang
CFLAGS			:=	-Wall -Werror -Wextra $(MACROS)

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
	@$(CC) $(CFLAGS) $(LIBS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) ready!$(DEFAULT)"

.c.o:
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	@make -s -C $(PATH_LIBFT)

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
