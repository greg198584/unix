/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 16:05:22 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/26 18:35:20 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>

char	*ft_set_var(t_list *env, char *code)
{
	char	*var;

	var = ft_find_element(env, code);
	return (var);
}

char	*ft_set_pwd(t_list *env)
{
	char	*pwd;

	pwd = ft_pwd();
	ft_setenv_list(env, "PWD", pwd);
	return (pwd);
}

void	ft_init_env(t_list *lst)
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
