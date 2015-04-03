/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 10:08:08 by glafitte          #+#    #+#             */
/*   Updated: 2015/04/03 13:58:17 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH2_H
# define FT_SH2_H

# include "libft.h"

# define PATH		"/bin:/sbin:/usr/bin:/usr/sbin"
# define ENV		"/usr/bin/env"

typedef struct		s_env
{
	char			*data;
	struct s_env	*next;
	struct s_env	*prev;
}					t_env;

typedef struct		s_opt
{
	int				(*func_ptr)(t_env *env, char **arg);
	char			*key;
}					t_opt;

char				ft_strcmp_sh(const char *s1, const char *s2, char equal);

#endif
