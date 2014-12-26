/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 16:08:12 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/26 19:37:20 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <unistd.h>

int	ft_cd(char **arg)
{
	if (arg[1] != NULL)
	{
		if (access(arg[1], F_OK) == -1)
		{
			ft_putstr_fd("cd : no such file or directory: ", 2);
			ft_putendl_fd(arg[1], 2);
			return (0);
		}
		if (access(arg[1], R_OK) == -1)
		{
			ft_putstr_fd("permission denied: ", 2);
			ft_putendl_fd(arg[1], 2);
			return (0);
		}
		if (chdir(arg[1]) == -1)
		{
			ft_error("you cannot access to this directory\n");
			return (0);
		}
		return (1);
	}
	ft_error("usage: cd directory\n");
	return (0);
}
