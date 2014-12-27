/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:34:00 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/27 15:44:36 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <unistd.h>

int	ft_cd(const char **arr)
{
	if (arr[1] != NULL)
	{
		if (access(arr[1], F_OK) == -1)
		{
			ft_error("no such file or directory: ", "cd");
			(void)ft_putendl(arr[1]);
			return (0);
		}
		if (access(arr[1], R_OK) == -1)
		{
			ft_error("permission denied: ", "cd");
			(void)ft_putendl(arr[1]);
			return (0);
		}
		if (chdir(arr[1]) == -1)
		{
			ft_error("you cannot access to this directory\n", "cd");
			return (0);
		}
		return (1);
	}
	ft_error("usage: cd directory\n", "cd");
	return (0);
}
