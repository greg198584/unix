/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 16:37:09 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/27 10:20:14 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_ls.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

char			*ft_str_to_dir(char const *s1, char const *s2)
{
	return (ft_strrep(ft_strrep("%s/%s", "%s", s1, ONE), "%s", s2, ONE));
}

void			ft_perror(char *dir_path)
{
	perror(ft_strrep("ft_ls: %s", "%s", dir_path, 0));
	exit(EXIT_FAILURE);
}

static void		ft_checkfiles(t_list *list, int opt)
{
	while (list != NULL && (opt & RECURSIVE))
	{
		if (list->type == DT_DIR)
		{
			if (ft_strcmp(list->path, ".") && ft_strcmp(list->path, ".."))
			{
				ft_putendl(ft_strrep("\n%s:", "%s", list->path, ONE));
				ft_get_dir(list->path, opt);
			}
		}
		list = list->next;
	}
}

static void		ft_call_get_dir(t_list *list, int opt)
{
	t_maxp	*p;

	p = (t_maxp *)ft_memalloc(sizeof(t_maxp));
	list = list->next;
	p = ft_set_params(list);
	ft_merge(&list, opt);
	ft_list_print(list, p, opt);
	ft_checkfiles(list, opt);
	ft_list_clear(&list);
}

void			ft_get_dir(char *dir_path, int opt)
{
	DIR				*d;
	t_list			*list;
	struct dirent	*e;
	struct stat		st;

	if (!(d = opendir(dir_path)) ||
		!(list = (t_list *)ft_memalloc(sizeof(t_list))))
	{
		if (errno == EACCES)
			return ;
		ft_perror(dir_path);
	}
	while ((e = readdir(d)) != NULL)
	{
		if (e->d_name[0] == '.' && !(opt & ALLREP))
			continue;
		if (lstat(ft_str_to_dir(dir_path, e->d_name), &st) == -1)
			break ;
		list = ft_list_new(list, e, st, ft_str_to_dir(dir_path, e->d_name));
		if (!ft_strcmp(e->d_name, ".") || !(ft_strcmp(e->d_name, "..")))
			continue;
	}
	if (list->next != NULL)
		ft_call_get_dir(list, opt);
	closedir(d);
}
