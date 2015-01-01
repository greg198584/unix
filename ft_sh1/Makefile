# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/25 14:02:08 by glafitte          #+#    #+#              #
#    Updated: 2014/12/31 15:41:15 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = ft_minishell1
CFLAGS = -Wall -Werror -Wextra -g -I include/
LIBFT = lib/libft/
LIBFTPRINTF = lib/ft_printf/
CC = gcc
SRCS =	src/main.c \
		src/checking.c \
		src/exec.c \
		src/pwd.c \
		src/cd.c \
		src/setenv.c \
		src/unsetenv.c \
		src/manage_list.c \
		src/free.c \
		src/error.c \
		src/init_list.c \
		src/env.c \
		src/init.c \
		src/var.c \
		src/tool.c \
		src/string.c \
		src/builtins.c \
		\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT) fclean
	@make -C $(LIBFT)
	@make -C $(LIBFTPRINTF) fclean
	@make -C $(LIBFTPRINTF)
	$(CC) $(OBJ) -o $(NAME) -L $(LIBFT) -lft -L $(LIBFTPRINTF) -lftprintf
	@echo "\033[35;1m• \033[0mCompilation de $(NAME) ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

OBJ : $(OBJ)
	$(CC) -I include/ $< -c $(SRCS)

clean :
	@make -C $(LIBFT) clean
	@make -C $(LIBFTPRINTF) clean
	@echo "\033[35;1m• \033[0mRemoving object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean : clean
	@make -C $(LIBFT) fclean
	@make -C $(LIBFTPRINTF) fclean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re : fclean all
