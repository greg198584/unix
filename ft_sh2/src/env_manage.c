/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 20:52:27 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/23 22:53:04 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <stdlib.h>

static int	ft_help(char *cmd)
{
	ft_printf("ft_minishell1 : env: illegal option -- %s\n", cmd);
	ft_putendl("Usage: env [-i] [name=value ...]");
	return (1);
}

static int	ft_setenv_ignore(t_env *env, char **var_arg)
{
	char	*env_var;

	if (var_arg[0] != NULL && var_arg[1] != NULL)
		ft_setenv_list(env, var_arg[0], var_arg[1]);
	else
	{
		ft_help(var_arg[0]);
		return (-1);
	}
	env_var = ft_find_element(env, var_arg[0]);
	ft_printf("%s=%s\n", var_arg[0], env_var);
	return (0);
}

static int	ft_setenv_local(t_env *env, char **var_arg)
{
	if (var_arg[0] != NULL && var_arg[1] != NULL)
		ft_setenv_list(env, var_arg[0], var_arg[1]);
	else
	{
		ft_help(var_arg[0]);
		return (-1);
	}
	ft_display_lst(env, 0);
	return (0);
}

int			ft_env_manage(t_env *env, char **var)
{
	char	**arg;

	if (var[1] == NULL)
	{
		ft_display_lst(env, 0);
		return (0);
	}
	else
	{
		if (var[1][0] == '-' && var[1][1] == 'i')
		{
			arg = ft_strsplit(var[2], '=');
			ft_setenv_ignore(env, arg);
		}
		else
		{
			arg = ft_strsplit(var[1], '=');
			ft_setenv_local(env, arg);
		}
		ft_free_arg(arg);
	}
	return (0);
}
