# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 13:50:00 by glafitte          #+#    #+#              #
#    Updated: 2015/01/03 23:20:22 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT = ../libft
SRCS =ft_printf.c \
		ft_putnbr_hexa.c \
		ft_atoi_base.c \
		ft_get_base.c \
		ft_strpos.c \
		ft_convert_base.c \
		ft_option.c \
		ft_atoui.c \
		ft_uitoa.c \
		ft_uint.c \
		ft_string.c \
		ft_precision.c \
		ft_print_string.c \
		\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	@make -C $(LIBFT) fclean
	@make -C $(LIBFT)
	$(CC) $(FLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	@make -C $(LIBFT) clean
	@echo "\033[35;1m• \033[0mRemoving object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean : clean
	@make -C $(LIBFT) fclean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re : fclean all
