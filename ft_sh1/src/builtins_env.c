/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 13:04:19 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/02 21:01:01 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>

int	ft_setenv(t_env *env, char **arr)
{
	ft_putendl("Fonction SETENV");
	if (arr[1] != NULL && arr[2] != NULL)
		ft_setenv_list(env, arr[1], arr[2]);
	else
		ft_error("usage: setenv variable\n", "setenv");
	return (2);
}

int	ft_unsetenv(t_env *list, char **arr)
{
	ft_putendl("Fonction UNSETENV");
	if (arr[1] != NULL)
		ft_remove_element(&list, arr[1]);
	else
		ft_error("usage: unsetenv variable\n", "unsetenv");
	return (2);
}

int	ft_env(t_env *list, char **arg)
{
	ft_putendl("Fonction ENV");
	ft_env_opt(list, arg);
	return (2);
}
