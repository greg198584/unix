/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 16:23:10 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/27 16:28:00 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

static char		*ft_find_dir(DIR *dir, struct stat *cur)
{
	struct dirent	*dirent;
	struct stat		tmp;
	int				found;
	char			*foundDir;

	found = 0;
	while (!found && (dirent = readdir(dir)) != NULL)
	{
		if (lstat(dirent->d_name, &tmp) != 0)
			ft_puterror("error: unable to use lstat in my_pwd.c: l30!\n");
		if ((tmp.st_dev == cur->st_dev) && (tmp.st_ino == cur->st_ino))
			found = 1;
	}
	if ((foundDir = ft_strdup(dirent->d_name)) == NULL)
		ft_puterror("error: problem with strdup in my_pwd.c: l37!\n");
	if (closedir(dir) == -1)
		ft_puterror("error: problem during closedir in my_pwd.c: l39!\n");
	if (!found)
		ft_puterror("error: unable to find the current dir in my_pwd: l41!\n");
	return (foundDir);
}

static DIR	*ft_init_pwd(struct stat *cur, struct stat *parent)
{
	DIR		*dir;

	if (lstat(".", cur) != 0)
		ft_puterror("error: problem with lstat in my_pwd.c: l50!\n");
	chdir("..");
	if (lstat(".", parent) != 0)
		ft_puterror("error: problem with lstat in my_pwd.c: l53!\n");
	if (!(dir = opendir(".")))
		ft_puterror("error: unable to open the cur dir in my_pwd: l55!\n");
	return (dir);
}

static char	*ft_new_dir(char *foundDir, char *curDir)
{
	int		len;
	int		len2;

	len = ft_strlen(curDir);
	if (len != 1)
		curDir = ft_strcat(curDir, "/");
	if (foundDir)
	{
		len2 = ft_strlen(foundDir);
		if ((len + len2 + 1) > 256)
			ft_puterror("error: the path's size is too big in my_pwd.c: l71!\n");
		curDir = ft_strcat(curDir, foundDir);
		free(foundDir);
	}
	return (curDir);
}

static char	*ft_return_pwd()
{
	struct stat	cur;
	struct stat	parent;
	DIR			*dir;
	char		*curDir;
	char		*foundDir;

	dir = ft_init_pwd(&cur, &parent);
	if ((cur.st_dev == parent.st_dev) && (cur.st_ino == parent.st_ino))
	{
		if ((curDir = malloc(sizeof(char) * 256)) == NULL)
			ft_puterror("error: problem to malloc curDir in my_pwd.c: l92!\n");
		curDir[0] = '\0';
		foundDir = NULL;
	}
	else
	{
		foundDir = ft_find_dir(dir, &cur);
		curDir = ft_return_pwd();
	}
	return (ft_new_dir(foundDir, curDir));
}

char		*ft_pwd()
{
	char	*pwd;

	pwd = ft_return_pwd();
	if (chdir(pwd) == -1)
		ft_error("unable to find directory in my_pwd.c: l110\n", "error");
	return (pwd);
}
