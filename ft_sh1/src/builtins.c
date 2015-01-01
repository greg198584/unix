/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 15:41:35 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/01 22:49:10 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>

int		ft_exit(t_env *env, char **arg)
{
	ft_putendl("Fonction EXIT");
	ft_free_arg(arg);
	ft_free_list(env);
	return (43);
}

int		ft_print_pwd(t_env *env, char **arg)
{
	ft_putendl("Fonction PWD");
	char	*pwd;
	(void)arg;

	pwd = ft_find_element(env, "PWD");
	ft_putendl(pwd);
	return (1);
}
