/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 16:41:17 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/23 22:55:05 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static char		**ft_conv_lst(t_env *env)
{
	t_env	*tmp;
	char	**arr;
	int		i;
	int		count;

	count = 0;
	if (env == NULL)
		return (NULL);
	tmp = env->next;
	while (tmp != env)
	{
		++count;
		tmp = tmp->next;
	}
	if ((arr = malloc(sizeof(char *) * (count + 1))) == NULL)
		ft_puterror("Erreur d'allocation memoire exec.c: ligne 36\n");
	i = -1;
	tmp = env->next;
	while (tmp != env)
	{
		arr[++i] = ft_strdup(tmp->data);
		tmp = tmp->next;
	}
	arr[++i] = NULL;
	return (arr);
}

static char		*ft_pathfile(char *path, char *exec)
{
	char	*res;
	int		len;
	int		size;

	len = ft_strlen(path);
	size = (path[len - 1] == '/') ? len : len + 1;
	if ((res = malloc(sizeof(char) * (size + ft_strlen(exec) + 1))) == NULL)
		ft_puterror("Erreur d'allocation memoire exec.c: ligne 60\n");
	res[0] = '\0';
	res = ft_strcat(res, path);
	if (len != size)
		res[len] = '/';
	res[size] = '\0';
	res = ft_strcat(res, exec);
	return (res);
}

static char		ft_goodpath(char *str)
{
	int		i;
	char	path_bin;

	i = -1;
	path_bin = 0;
	while (str[++i] && path_bin == 0)
		if (str[i] == '/')
			path_bin = 1;
	return (path_bin);
}

static char		*ft_access(char *str, char *path)
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

int				ft_exec(t_env *env, char **exec_opt, char *path)
{
	pid_t	pid;
	int		statut;
	char	**env_local;
	char	*exec;

	env_local = ft_conv_lst(env);
	pid = fork();
	if (pid == -1)
		return (ft_error("Impossible de chercher le fils dans fork\n", "fork"));
	else if (pid == 0)
	{
		if ((exec = ft_access(exec_opt[0], path)) == NULL ||
				execve(exec, exec_opt, env_local) == -1)
			ft_notfound(exec);
	}
	else
		wait(&statut);
	ft_free_arg(env_local);
	return (0);
}
