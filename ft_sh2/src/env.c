/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 16:21:10 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/23 22:52:51 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	*ft_set_var(t_env *env, char *code)
{
	char	*var;

	var = ft_find_element(env, code);
	return (var);
}

char	*ft_set_pwd(t_env *env)
{
	char	*pwd;

	(void)env;
	pwd = ft_pwd();
	ft_setenv_list(env, "PWD", pwd);
	return (pwd);
}

void	ft_init_env(t_env *lst)
{
	char	*path;

	ft_setenv_list(lst, "_", ENV);
	path = ft_set_var(lst, "PATH");
	if (path == NULL)
	{
		ft_setenv_list(lst, "PATH", PATH);
		path = PATH;
	}
}
