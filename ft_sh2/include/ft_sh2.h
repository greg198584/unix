/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 10:08:08 by glafitte          #+#    #+#             */
/*   Updated: 2015/04/02 11:14:31 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH2_H
# define FT_SH2_H

# include "libft.h"

# define PATH		"/bin:/sbin:/usr/bin:/usr/sbin"
# define ENV		"/usr/bin/env"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define CYAN		"\033[1;36m"
# define BLUE		"\033[1;34m"
# define YELLOW		"\033[1;33m"

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

#endif
