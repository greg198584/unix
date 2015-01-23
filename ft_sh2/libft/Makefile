# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/19 11:11:25 by glafitte          #+#    #+#              #
#    Updated: 2015/01/20 12:00:15 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libft.a
INCLUDE = ../include/
CFLAGS = -Wall -Wextra -Werror -g -I $(INCLUDE)
CC = gcc
SRCS =	src/error.c \
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
		src/ft_striter.c \
		src/ft_striteri.c \
		src/ft_strmap.c \
		src/ft_strmapi.c \
		src/ft_strequ.c \
		src/ft_strnequ.c \
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
		src/ft_strrep.c \
		src/ft_match.c \
		src/ft_strndup.c \
		src/ft_active_bits.c \
		src/ft_strrev.c \
		src/ft_strnrep.c \
		src/ft_char_manip.c \
		src/ft_chartostr.c \
		src/get_next_line.c \
		\

SRCS_FTPRINTF =	ft_printf/ft_printf.c \
				ft_printf/ft_putnbr_hexa.c \
				ft_printf/ft_atoi_base.c \
				ft_printf/ft_get_base.c \
				ft_printf/ft_strpos.c \
				ft_printf/ft_convert_base.c \
				ft_printf/ft_option.c \
				ft_printf/ft_atoui.c \
				ft_printf/ft_uitoa.c \
				ft_printf/ft_uint.c \
				ft_printf/ft_string.c \
				ft_printf/ft_precision.c \
				ft_printf/ft_print_string.c \
				ft_printf/ft_ftoa.c \
				ft_printf/ft_atof.c \
				\

OBJ = $(SRCS:.c=.o)
OBJ_2 = $(SRCS_FTPRINTF:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(OBJ_2)
	@ar rc $(NAME) $(OBJ) $(OBJ_2)
	ranlib $(NAME)
	@echo "\033[35;1m• \033[0mCompilation de $(NAME) ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

OBJ : $(OBJ)
	$(CC) -I include/ $< -c $(SRCS)

OBJ_2 : $(OBJ_2)
	$(CC) -I include/ $< -c $(SRCS_FTPRINTF)

clean :
	@echo "\033[35;1m• \033[0mRemoving object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_2)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean : clean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re : fclean all
