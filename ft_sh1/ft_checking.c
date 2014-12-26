/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 16:04:34 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/26 19:37:31 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <stdlib.h>

static int	ft_exit(t_list *env, char **arg)
{
	ft_putendl("sorti du programme");
	ft_free_arg(arg);
	ft_free_list(env);
	exit(EXIT_SUCCESS);
	return (1);
}

static int	ft_call_option(char **arg, t_list *env)
{
	char	*pwd;

	if (!ft_strcmp(arg[0], "exit"))
		return (ft_exit(env, arg));
	else if(!ft_strcmp(arg[0], "cd"))
		return(ft_cd(arg));
	else if (!ft_strcmp(arg[0], "pwd"))
	{
		pwd = ft_find_element(env, "pwd");
		ft_putendl(pwd);
		return (1);
	}
		return (1);
	return (0);
}

int	ft_checking_arg(char *arg, t_list *env)
{
	char	**arg_chk;
	char	result;

	arg_chk = ft_str_to_wordtab(arg, ' ', '\t');
	if (arg_chk == NULL || arg_chk[0] == NULL)
		return (0);
	if (( result = ft_call_option(arg_chk, env)) != 0)
		return (result - 1);
	else
		(void)ft_exec(env, arg_chk, ft_find_element(env, "PATH"));
	ft_free_arg(arg_chk);
	return (0);
}
