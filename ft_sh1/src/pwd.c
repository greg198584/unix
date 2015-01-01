/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 16:23:10 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/29 16:08:29 by glafitte         ###   ########.fr       */
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
	char			*found_dir;

	found = 0;
	while (!found && (dirent = readdir(dir)) != NULL)
	{
		if (lstat(dirent->d_name, &tmp) != 0)
			ft_puterror("erreur: lstat dans pwd.c: ligne 31\n");
		if ((tmp.st_dev == cur->st_dev) && (tmp.st_ino == cur->st_ino))
			found = 1;
	}
	if ((found_dir = ft_strdup(dirent->d_name)) == NULL)
		ft_puterror("erreur: strdup dans pwd.c: ligne 36\n");
	if (closedir(dir) == -1)
	{
		ft_puterror("erreur: erreur lors de la fermeture du dossier pwd.c: "); 
		ft_puterror("ligne 38\n");
	}
	if (!found)
		ft_puterror("error: unable to find the current dir in my_pwd: l41!\n");
	return (found_dir);
}

static DIR	*ft_init_pwd(struct stat *current, struct stat *parent)
{
	DIR		*dir;

	if (lstat(".", current) != 0)
		ft_puterror("error: lstat dossier courant pwd.c: ligne 50!\n");
	chdir("..");
	if (lstat(".", parent) != 0)
		ft_puterror("erreur: lstat dossier parent pwd.c: ligne 53\n");
	if (!(dir = opendir(".")))
		ft_puterror("erreur: ouverture de dossier  pwd.c: ligne 55\n");
	return (dir);
}

static char	*ft_new_dir(char *found_dir, char *current_dir)
{
	int		len;
	int		len2;

	len = ft_strlen(current_dir);
	if (len != 1)
		current_dir = ft_strcat(current_dir, "/");
	if (found_dir)
	{
		len2 = ft_strlen(found_dir);
		if ((len + len2 + 1) > 256)
			ft_puterror("erreur: taille de path trop grande pwd.c: ligne 70\n");
		current_dir = ft_strcat(current_dir, found_dir);
		free(found_dir);
	}
	return (current_dir);
}

static char	*ft_return_pwd()
{
	struct stat	cur;
	struct stat	parent;
	DIR			*dir;
	char		*current_dir;
	char		*found_dir;

	dir = ft_init_pwd(&cur, &parent);
	if ((cur.st_dev == parent.st_dev) && (cur.st_ino == parent.st_ino))
	{
		if ((current_dir = malloc(sizeof(char) * 256)) == NULL)
			ft_puterror("Erreur: allocation memoire  pwd.c: ligne 89\n");
		current_dir[0] = '\0';
		found_dir = NULL;
	}
	else
	{
		found_dir = ft_find_dir(dir, &cur);
		current_dir = ft_return_pwd();
	}
	return (ft_new_dir(found_dir, current_dir));
}

char		*ft_pwd()
{
	char	*pwd;

	pwd = ft_return_pwd();
	if (chdir(pwd) == -1)
		ft_error("Repertoire introuvable  pwd.c: ligne 107\n", "error");
	return (pwd);
}
