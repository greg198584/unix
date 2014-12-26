/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 16:49:39 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/26 17:43:54 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

static char	*ft_access(char *str, char *path)
{
	char	**arg;
	int		i;
	char	*exec;

	if (ft_goodpath(str))
		return ((access(str, F_OK | X_OK) == -1) ? NULL : str);
	arg = ft_str_to_wordtab(path, ':', ':');
	i = -1;
	while (arg[++i] != NULL)
	{
		exec = ft_pathfile(arg[i], str);
		if (access(exec, F_OK | X_OK) != -1)
		{
			ft_free_arg(arg);
			return (exec);
		}
		free(exec);
	}
	return (NULL);
}

char		ft_exec(t_list *env, char **opt, char *path)
{
	pid_t	pid;
	int		status;
	char	**env_local;
	char	*exec;

	env_local = ft_conv_list(env);
	pid = fork();
	if (pid == -1)
	{
		ft_error("impossible de rechercher le fils pour fork");
		return (1);
	}
	else if (pid == 0)
	{
		if ((exec = ft_access(opt[0], path)) == NULL ||
				execve(exec, opt, env_local) == -1)
		{
			ft_free_arg(env_local);
			return (-1);
		}
	}
	else
		wait(&status);
	ft_free_arg(env_local);
	return (0);
}
