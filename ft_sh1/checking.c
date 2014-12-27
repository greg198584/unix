/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 16:14:05 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/27 16:52:36 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <stdlib.h>

static char	ft_exit(t_env *env, char **arr)
{
	ft_free_arr(arr);
	ft_free_lst(env);
	return (43);
}

static int	ft_checking_opt(char **arr, t_env *env)
{
	char		*pwd;

	if (ft_strncmp(arr[0], "exit", 0))
		return (ft_exit(env, arr));
}

int			ft_check(char *str, t_env *env)
{
	char	**arr;
	char	res;

	arr = ft_str_to_wordtab(str, ' ', '\t');
	if (arr == NULL || arr[0] == NULL)
		return (0);
	if ((res = ft_checking_opt(arr, env)) != 0)
	{
		if (res != 43)
			ft_free_arr(arr);
		return (res - 1);
	}
	else
		(void)ft_exec(env, arr, ft_find_element(env, "PATH"));
	ft_free_arr(arr);
	return (0);
}
