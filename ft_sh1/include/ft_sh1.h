/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 14:30:12 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/01 16:40:02 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

# define PATH	"/bin:/sbin:/usr/bin:/usr/sbin"
# define ENV	"/usr/bin/env"

# define BUFF	512

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define CYAN	"\033[1;36m"
# define BLUE	"\033[1;34m"
# define YELLOW	"\033[1;33m"

typedef struct		s_env
{
	char			*data;
	struct s_env	*next;
	struct s_env	*prec;
}					t_env;

typedef struct		s_opt
{
	int				(*func_ptr)(t_env *env, char **arg);
	char			*key;
}					t_opt;

char				ft_conf(char *cmd);
void				ft_puterror(const char *error);
void				ft_error(const char *error, const char *var);
char				ft_env_error(char *env, char type, int pos);
int					ft_cd(t_env *env, char **arr);
void				ft_init(char *str);
void				ft_prompt(t_env *env, int change);
char				ft_signal();
void				ft_display_lst(t_env *lst, char type);
void				ft_add_element(t_env **list, char *val, char *start);
t_env				*ft_create_list(char **env);
void				ft_remove_element(t_env **lst, char *value);
char				ft_strcmp_shell(const char *s1, const char *s2, char equal);
char				*ft_find_element(t_env *lst, char *value);
void				ft_setenv_list(t_env *lst, char *var, char *value);
char				*ft_pwd();
char				*ft_set_var(t_env *env, char *code);
char				*ft_set_pwd(t_env *env);
void				ft_init_env(t_env *lst);
char				**ft_str_to_wordtab(char *path, char end, char end1);
char				ft_exec(t_env *env, char **exec_opt, char *path);
int					ft_check(char *str, t_env *env);
void				ft_putstr_color(const char *str, const char *color, int i);
int					ft_exit(t_env *env, char **arg);
int					ft_print_pwd(t_env *env, char **arg);
int					ft_free_list(t_env *list);
int					ft_free_arg(char **arg);

#endif
