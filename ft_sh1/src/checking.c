/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 16:14:05 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/02 22:12:54 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <stdlib.h>

t_opt		tab_func[] =
{
	{&ft_exit, "exit"},
	{&ft_cd, "cd"},
	{&ft_print_pwd, "pwd"},
	{&ft_env, "env"},
	{&ft_setenv, "setenv"},
	{&ft_unsetenv, "unsetenv"},
	{NULL, NULL}
};

static int	ft_checking_opt(char **arg, t_env *env)
{
	int		i;

	i = -1;
	while (tab_func[++i].key != NULL)
	{
		if (ft_strcmp_shell(arg[0], tab_func[i].key, 0))
			return (tab_func[i].func_ptr(env, arg));
	}
	return (0);
}

int			ft_check(char *str, t_env *env)
{
	char	**arg;
	int		res;

	arg = ft_str_to_wordtab(str, ' ', '\t');
	if (arg == NULL || arg[0] == NULL)
		return (0);
	if ((res = ft_checking_opt(arg, env)) != 0)
	{
		if (res != 43)
			ft_free_arg(arg);
		return (res - 1);
	}
	else
	{
		ft_printf("arg = [%s]\n", arg[0]);
		ft_exec(env, arg, ft_find_element(env, "PATH"));
	}
	ft_free_arg(arg);
	return (1);
}
