/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 14:30:12 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/26 19:37:27 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include "../lib/libft/libft.h"

# define BUFF		512

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define CYAN		"\033[1;36m"
# define BLUE		"\033[1;34m"
# define YELLOW		"\033[1;33m"

# define PATH		"/bin:/sbin:/usr/bin:/usr/sbin"
# define ENV		"/usr/bin/env"

typedef struct		s_list
{
	char			*data;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

t_list	*ft_create_list(char **env);
int		ft_setenv(void);
int		ft_unsetenv(void);
char	*ft_pwd();
void	ft_error(const char *error);
int		ft_checking_arg(char *arg, t_list *env);
char	**ft_str_to_wordtab(char *path, char end, char end1);
char	*ft_find_element(t_list *list, char *value);
void	ft_setenv_list(t_list *list, char *var, char *value);
char	**ft_str_to_wordtab(char *path, char end, char end1);
void	ft_free_arg(char **arg);
char	ft_exec(t_list *env, char **opt, char *path);
char	ft_goodpath(char *str);
char	*ft_pathfile(char *path, char *exec);
char	**ft_conv_list(t_list *env);
void	ft_remove_element(t_list **list, char *value);
void	ft_add_element(t_list **list, char *val, char *start);
char	*ft_set_var(t_list *env, char *code);
char	*ft_set_pwd(t_list *env);
void	ft_init_env(t_list *lst);
void	ft_init(char *str);
void	ft_prompt(t_list *env, char change);
char	ft_signal();
void	ft_free_list(t_list *list);
int		ft_cd(char **arg);

#endif
