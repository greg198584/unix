/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 16:37:01 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/02 12:08:59 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_ls.h"
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

static	char	*ft_getspace(int p, int l)
{
	char	*s;
	int		i;

	i = ft_strlen(ft_itoa(p)) - ft_strlen(ft_itoa(l));
	s = ft_strdup(" ");
	while (i--)
		s = ft_strcat(s, " ");
	return (s);
}

char			*ft_get_time(t_list *list, int opt)
{
	char		**split_p;
	char		**split_e;
	char		*str;

	if (list == NULL)
		return (NULL);
	str = ft_strrep(ctime(&list->stats.st_birthtime), "\n", "", ONE);
	split_e = ft_strsplit(str, ' ');
	if (opt & DATE_RETURN)
		return (split_e[4]);
	split_p = ft_strsplit(split_e[3], ':');
	str = ft_strrep("%1 .%2 %3:%4", "%1", split_e[1], ONE);
	if (ft_atoi(split_e[2]) < 10)
		str = ft_strrep(str, ".", "  ", ONE);
	else
		str = ft_strrep(str, ".", " ", ONE);
	str = ft_strrep(str, "%2", split_e[2], ONE);
	str = ft_strrep(str, "%3", split_p[0], ONE);
	str = ft_strrep(str, "%4", split_p[1], ONE);
	return (str);
}

static char		*ft_getright(int mode)
{
	if ((mode & S_IRUSR) || (mode & S_IRGRP) || (mode & S_IROTH))
		return ("r");
	if ((mode & S_IWUSR) || (mode & S_IWGRP) || (mode & S_IWOTH))
		return ("w");
	if ((mode & S_IXUSR) || (mode & S_IXGRP) || (mode & S_IXOTH))
		return ("x");
	return ("-");
}

static char		*ft_get_root(t_list *list)
{
	char	*s;
	char	*type_list;

	s = "##########";
	type_list = TYPE_LIST;
	s = ft_strrep(s, "#", ft_strndup(&type_list[list->entry->d_type], 1), ONE);
	s = ft_strrep(s, "#", ft_getright(list->stats.st_mode & S_IRUSR), ONE);
	s = ft_strrep(s, "#", ft_getright(list->stats.st_mode & S_IWUSR), ONE);
	s = ft_strrep(s, "#", ft_getright(list->stats.st_mode & S_IXUSR), ONE);
	s = ft_strrep(s, "#", ft_getright(list->stats.st_mode & S_IRGRP), ONE);
	s = ft_strrep(s, "#", ft_getright(list->stats.st_mode & S_IWGRP), ONE);
	s = ft_strrep(s, "#", ft_getright(list->stats.st_mode & S_IXGRP), ONE);
	s = ft_strrep(s, "#", ft_getright(list->stats.st_mode & S_IROTH), ONE);
	s = ft_strrep(s, "#", ft_getright(list->stats.st_mode & S_IWOTH), ONE);
	s = ft_strrep(s, "#", ft_getright(list->stats.st_mode & S_IXOTH), ONE);
	return (s);
}

char			*ft_get_long_output(t_list *list, t_maxp *p)
{
	char			*s;

	s = "%1 .%2 %3 %4 .%5 %6 %7";
	s = ft_strrep(s, ".", ft_getspace(p->max_nlink, list->stats.st_nlink), ONE);
	s = ft_strrep(s, ".", ft_getspace(p->max_bsize, list->stats.st_size), ONE);
	s = ft_strrep(s, "%1", ft_get_root(list), ONE);
	s = ft_strrep(s, "%2", ft_itoa(list->stats.st_nlink), ONE);
	s = ft_strrep(s, "%3", getpwuid(list->stats.st_uid)->pw_name, ONE);
	s = ft_strrep(s, "%4", getgrgid(list->stats.st_gid)->gr_name, ONE);
	s = ft_strrep(s, "%5", ft_itoa(list->stats.st_size), ONE);
	s = ft_strrep(s, "%6", ft_get_time(list, TIME_RETURN), ONE);
	s = ft_strrep(s, "%7", ft_strdup(ft_strrchr(list->path, '/') + 1), ONE);
	return (s);
}
