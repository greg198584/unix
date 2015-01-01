/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:34:00 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/31 15:56:27 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <unistd.h>

int		ft_cd(t_env *env, char **arg)
{
	(void)env;

	if (arg[1] != NULL)
	{
		if (access(arg[1], F_OK) == -1)
		{
			ft_error("repertoire introuvable: ", "cd");
			(void)ft_putendl(arg[1]);
			return (0);
		}
		if (access(arg[1], R_OK) == -1)
		{
			ft_error("Permission refuse: ", "cd");
			(void)ft_putendl(arg[1]);
			return (0);
		}
		if (chdir(arg[1]) == -1)
		{
			ft_error("impossible d'acceder au dossier\n", "cd");
			return (0);
		}
		return (1);
	}
	ft_error("usage: cd {nom du repertoire}\n", "cd");
	return (0);
}
