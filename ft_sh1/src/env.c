/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 16:21:10 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/27 16:31:04 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>

char	*ft_set_var(t_env *env, char *code)
{
	char	*var;

	var = ft_find_element(env, code);
	return (var);
}

char	*ft_set_pwd(t_env *env)
{
	char	*pwd;

	pwd = ft_pwd();
	ft_setenv_lst(env, "PWD", pwd);
	return (pwd);
}

void	ft_init_env(t_env *lst)
{
	char	*path;

	ft_setenv_lst(lst, "_", ENV);
	path = ft_set_var(lst, "PATH");
	if (path == NULL)
	{
		ft_setenv_lst(lst, "PATH", PATH);
		path = PATH;
	}
}
