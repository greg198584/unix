/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 11:20:37 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/02 10:39:50 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

t_list		*ft_list_create(struct dirent *entry, struct stat stats, char *path)
{
	t_list		*list;

	if ((list = (t_list *)ft_memalloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->name = entry->d_name;
	list->path = path;
	list->type = entry->d_type;
	list->full = ft_str_to_dir(path, entry->d_name);
	list->entry = entry;
	list->stats = stats;
	list->next = NULL;
	return (list);
}

t_list		*ft_list_new(t_list *list, struct dirent *entry, struct stat stats,
						char *path)
{
	t_list	*elem;
	t_list	*ptr;

	ptr = list;
	elem = ft_list_create(entry, stats, path);
	if (list != NULL)
	{
		while (list->next != NULL)
			list = list->next;
		list->next = elem;
		return (ptr);
	}
	return (elem);
}

void		ft_list_print(t_list *list, t_maxp *p, int opt)
{
	char	*s;

	if ((s = (char *)ft_memalloc(sizeof(char) * 1024)) == NULL)
		return ;
	if (opt & LONG)
		ft_putstr(ft_strrep("Total %s\n", "%s", ft_itoa(p->block_alloc), 0));
	while (list != NULL)
	{
		if (list->entry->d_type == DT_LNK && opt & LONG)
		{
			ft_putstr(ft_get_long_output(list, p));
			if (!readlink(list->path, s, 1024))
				return ;
			ft_putstr(ft_strrep(" -> %s\n", "%s", s, ONE));
			list = list->next;
			continue ;
		}
		if (opt & LONG)
			ft_putendl(ft_get_long_output(list, p));
		else
			ft_putendl(ft_strdup(ft_strrchr(list->path, '/') + 1));
		list = list->next;
	}
}

void		ft_list_clear(t_list **begin_list)
{
	if ((*begin_list)->next)
		ft_list_clear(&(*begin_list)->next);
	*begin_list = NULL;
	free(*begin_list);
}

t_maxp		*ft_set_params(t_list *list)
{
	t_maxp			*p;
	unsigned int	count;

	count = 0;
	if ((p = (t_maxp *)ft_memalloc(sizeof(t_maxp))) == NULL)
		return (NULL);
	p->max_nlink = 0;
	p->max_bsize = 0;
	p->block_alloc = 0;
	while (list != NULL)
	{
		if (list->stats.st_size > p->max_bsize)
			p->max_bsize = list->stats.st_size;
		if (list->stats.st_nlink > p->max_nlink)
			p->max_nlink = list->stats.st_nlink;
		p->block_alloc = (count += list->stats.st_blocks);
		list = list->next;
	}
	return (p);
}
