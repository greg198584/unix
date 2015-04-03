# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/19 11:11:25 by glafitte          #+#    #+#              #
#    Updated: 2015/04/03 14:46:27 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -g -I ../include/
CC = gcc
SRCS =	src/ft_freetab.c \
		src/ft_putcolor.c \
		src/error.c \
		src/ft_abs.c \
		src/ft_atoi.c \
		src/ft_isalnum.c \
		src/ft_isalpha.c \
		src/ft_isascii.c \
		src/ft_isdigit.c \
		src/ft_islower.c \
		src/ft_isupper.c \
		src/ft_isprint.c \
		src/ft_isspace.c \
		src/ft_toupper.c \
		src/ft_tolower.c \
		\
		src/ft_strlen.c \
		src/ft_strcmp.c \
		src/ft_strncmp.c \
		src/ft_strchr.c \
		src/ft_strrchr.c \
		src/ft_strstr.c \
		src/ft_strnstr.c \
		src/ft_strcat.c \
		src/ft_strncat.c \
		src/ft_strlcat.c \
		src/ft_strcpy.c \
		src/ft_strncpy.c \
		src/ft_strdup.c \
		src/ft_strnew.c \
		src/ft_strdel.c \
		src/ft_strclr.c \
		src/ft_strjoin.c \
		src/ft_strtrim.c \
		src/ft_strsub.c \
		src/ft_strsplit.c \
		\
		src/ft_bzero.c \
		src/ft_memset.c \
		src/ft_memcpy.c \
		src/ft_memccpy.c \
		src/ft_memmove.c \
		src/ft_memchr.c \
		src/ft_memcmp.c \
		src/ft_memalloc.c \
		src/ft_memdel.c \
		\
		src/ft_putchar.c \
		src/ft_putchar_fd.c \
		src/ft_putstr.c \
		src/ft_putstr_fd.c \
		src/ft_putendl.c \
		src/ft_putendl_fd.c \
		src/ft_putnbr.c \
		src/ft_putnbr_fd.c \
		\
		src/ft_itoa.c \
		src/ft_pow.c \
		src/ft_match.c \
		src/ft_strndup.c \
		src/ft_active_bits.c \
		src/ft_strrev.c \
		src/ft_chartostr.c \
		src/get_next_line.c \
		src/ft_fprintf.c \
		\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "\033[35;1m• \033[0mCompilation de $(NAME) ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

OBJ : $(OBJ)
	$(CC) $(CFLAGS) $< -c $(SRCS)

clean :
	@echo "\033[35;1m• \033[0mRemoving object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean : clean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re : fclean all
