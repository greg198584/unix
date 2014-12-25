/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 16:49:39 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/25 11:49:47 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <unistd.h>
#include <sys/wait.h>

int	ft_exec(char *prg)
{
	pid_t	father;

	father = fork();
	if (father > 0)
	{
		wait(0);
		return (0);
	}
	if (father == 0)
		execve(ft_strjoin("/bin/", prg), NULL, NULL);
	else
	{
		ft_putstr("ft_minishell1: command not found: ");
		ft_putendl(prg);
	}
	return (0);
}
