# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/25 14:02:08 by glafitte          #+#    #+#              #
#    Updated: 2014/12/26 18:33:57 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = ft_minishell1
CFLAGS = -Wall -Werror -Wextra -g -I include/
LIBFT = lib/libft/
SRCS =	main.c \
		ft_checking.c \
		ft_exec.c \
		ft_pwd.c \
		ft_cd.c \
		ft_setenv.c \
		ft_unsetenv.c \
		ft_env.c \
		ft_str_wordtab.c \
		ft_free.c \
		ft_path.c \
		ft_error.c \
		ft_init_list.c \
		ft_prompt.c \
		\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	@make -C $(LIBFT) fclean
	@make -C $(LIBFT)
	gcc -I include/ -c $(SRCS)
	gcc $(OBJ) -o $(NAME) -L $(LIBFT) -lft
	@echo "\033[35;1m• \033[0mCompilation de $(NAME) ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

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
