# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 12:23:21 by ugdaniel          #+#    #+#              #
#    Updated: 2022/02/25 22:03:39 by ugdaniel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		=	srcs/array/2d_array.c \
				srcs/array/ft_split.c \
				srcs/array/str_array.c \
				srcs/char/ft_isalnum.c \
				srcs/char/ft_isalpha.c \
				srcs/char/ft_isascii.c \
				srcs/char/ft_isdigit.c \
				srcs/char/ft_islower.c \
				srcs/char/ft_isprint.c \
				srcs/char/ft_isspace.c \
				srcs/char/ft_isupper.c \
				srcs/char/ft_tolower.c \
				srcs/char/ft_toupper.c \
				srcs/ft_printf/ft_printf.c \
				srcs/ft_printf/ft_dprintf.c \
				srcs/ft_printf/ft_dprintf-internal.c \
				srcs/ft_printf/conversions/char.c \
				srcs/ft_printf/conversions/hex.c \
				srcs/ft_printf/conversions/int.c \
				srcs/ft_printf/conversions/long.c \
				srcs/ft_printf/conversions/ptr.c \
				srcs/ft_printf/conversions/string.c \
				srcs/ft_printf/conversions/uint.c \
				srcs/ft_printf/conversions/ulong.c \
				srcs/list/ft_lstadd_back.c \
				srcs/list/ft_lstadd_front.c \
				srcs/list/ft_lstclear.c \
				srcs/list/ft_lstdelone.c \
				srcs/list/ft_lstiter.c \
				srcs/list/ft_lstlast.c \
				srcs/list/ft_lstmap.c \
				srcs/list/ft_lstnew.c \
				srcs/list/ft_lstsize.c \
				srcs/math/ft_abs.c \
				srcs/mem/ft_bzero.c \
				srcs/mem/ft_calloc.c \
				srcs/mem/ft_memccpy.c \
				srcs/mem/ft_memchr.c \
				srcs/mem/ft_memcmp.c \
				srcs/mem/ft_memcpy.c \
				srcs/mem/ft_memmove.c \
				srcs/mem/ft_memset.c \
				srcs/mem/ft_xmalloc.c \
				srcs/string/ft_atoi.c \
				srcs/string/ft_itoa.c \
				srcs/string/ft_len_to_char.c \
				srcs/string/ft_len_to_space.c \
				srcs/string/ft_str_tolower.c \
				srcs/string/ft_str_toupper.c \
				srcs/string/ft_strcat.c \
				srcs/string/ft_strchr.c \
				srcs/string/ft_strcmp.c \
				srcs/string/ft_strcpy.c \
				srcs/string/ft_strdup.c \
				srcs/string/ft_strjoin.c \
				srcs/string/ft_strjoin_3.c \
				srcs/string/ft_strlcat.c \
				srcs/string/ft_strlcpy.c \
				srcs/string/ft_strlen.c \
				srcs/string/ft_strmapi.c \
				srcs/string/ft_strncat.c \
				srcs/string/ft_strncmp.c \
				srcs/string/ft_strncpy.c \
				srcs/string/ft_strndup.c \
				srcs/string/ft_strnlen.c \
				srcs/string/ft_strnstr.c \
				srcs/string/ft_strrchr.c \
				srcs/string/ft_strsplit.c \
				srcs/string/ft_strtrim.c \
				srcs/string/ft_substr.c \
				srcs/write/ft_puchar.c \
				srcs/write/ft_putchar_fd.c \
				srcs/write/ft_putendl.c \
				srcs/write/ft_putendl_fd.c \
				srcs/write/ft_putnbr.c \
				srcs/write/ft_putnbr_fd.c \
				srcs/write/ft_putstr.c \
				srcs/write/ft_putstr_fd.c
OBJS		=	$(SRCS:.c=.o)
HEADERS		=	-I include

CC			=	clang
FLAGS		=	-Wall -Wextra -Werror

# Colors
_default	=	\033[39m
_green		= 	\033[92m
_magenta	= 	\033[95m
_yellow		= 	\033[33m
_blue		= 	\033[34m
_red		= 	\033[91m
_cyan		= 	\033[96m

all: $(NAME)

$(NAME): text1 $(OBJS)
	@ar rcs $(NAME) $(OBJS) && printf "\033[2K\r$(_green)$(NAME) ready!$(_default)\n"

.c.o:
	$(CC) $(FLAGS) $(HEADERS) -o $@ -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@test -f $(NAME) && rm -f $(NAME) || true
	@echo "$(_default)$(_red)Cleaned $(NAME)"

re: fclean all

text1:
	@echo "Compiling $(NAME)... \t$(_default)"

.PHONY: all clean fclean re text1
