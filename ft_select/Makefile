# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/25 14:02:08 by glafitte          #+#    #+#              #
#    Updated: 2015/01/20 11:41:50 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = ft_select
CFLAGS = -Wall -Wextra -Werror -g -I include/
LIBFT = libft/
CC = gcc
SRCS =	src/main.c \
		\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT) re
	$(CC) $(OBJ) -o $(NAME) -L $(LIBFT) -lft $(LIBX)
	@echo "\033[35;1m• \033[0mCompilation de $(NAME) ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

OBJ : $(OBJ)
	$(CC) -I include/ $< -c $(SRCS)

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
