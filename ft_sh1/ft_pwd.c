/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 16:04:37 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/26 18:46:54 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>

static char		*ft_find_dir(DIR *dir, struct stat *cur)
{
	struct dirent		*dirent;
	struct stat		tmp;
	int			found;
	char			*found_dir;

	found = 0;
	while (!found && (dirent = readdir(dir)) != NULL)
	{
		if (lstat(dirent->d_name, &tmp) != 0)
			ft_error("error: unable to use lstat in my_pwd.c: l30!\n");
		if ((tmp.st_dev == cur->st_dev) && (tmp.st_ino == cur->st_ino))
			found = 1;
	}
	if ((found_dir = ft_strdup(dirent->d_name)) == NULL)
		ft_error("error: problem with strdup in my_pwd.c: l37!\n");
	if (closedir(dir) == -1)
		ft_error("error: problem during closedir in my_pwd.c: l39!\n");
	if (!found)
		ft_error("error: unable to find the current dir in my_pwd: l41!\n");
	return (found_dir);
}

static DIR	*ft_init_pwd(struct stat *cur, struct stat *parent)
{
	DIR		*dir;

	if (lstat(".", cur) != 0)
		ft_error("error: problem with lstat in my_pwd.c: l50!\n");
	chdir("..");
	if (lstat(".", parent) != 0)
		ft_error("error: problem with lstat in my_pwd.c: l53!\n");
	if (!(dir = opendir(".")))
		ft_error("error: unable to open the cur dir in my_pwd: l55!\n");
	return (dir);
}

static char	*ft_new_str(char *found_dir, char *current_dir)
{
	int	len;
	int	len2;

	len = ft_strlen(current_dir);
	if (len != 1)
		current_dir = ft_strcat(current_dir, "/");
	if (found_dir)
	{
		len2 = ft_strlen(found_dir);
		if ((len + len2 + 1) > 256)
			ft_error("error: the path's size is too big in my_pwd.c: l71!\n");
		current_dir = ft_strcat(current_dir, found_dir);
		free(found_dir);
	}
	return (current_dir);
}

/*
 ** brief: rec function used to found our directory
 ** return: return the good path
 */
static char	*ft_return_pwd()
{
	struct stat	cur;
	struct stat	parent;
	DIR		*dir;
	char	*current_dir;
	char	*found_dir;

	dir = ft_init_pwd(&cur, &parent);
	if ((cur.st_dev == parent.st_dev) && (cur.st_ino == parent.st_ino))
	{
		if ((current_dir = malloc(sizeof(char) * 256)) == NULL)
			ft_error("error: problem to malloc curDir in my_pwd.c: l92!\n");
		current_dir[0] = '\0';
		found_dir = NULL;
	}
	else
	{
		found_dir = ft_find_dir(dir, &cur);
		current_dir = ft_return_pwd();
	}
	return (ft_new_str(found_dir, current_dir));
}
char	*ft_pwd()
{
	char	*pwd;

	pwd = ft_return_pwd();
	if (chdir(pwd) == -1)
		ft_error("impossible de trouver le repertoire");
	return (pwd);
}
