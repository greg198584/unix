/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 16:37:05 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/02 11:43:02 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define OPT_ERROR		-0x1

# define LONG 			0x01
# define RECURSIVE		0x02
# define ALLREP			0x04
# define REVERSE		0x08
# define TIME			0x10

# define OPT_LIST		"lRart"
# define TYPE_LIST		"-fc-d-b---l-s-w"
# define LOCALDIR		"."
# define DEBUG_OPT		0x01

# define ONE			0x0
# define ALL			0x1
# define DATE_RETURN	0x1
# define TIME_RETURN	0x0

# include <dirent.h>
# include <sys/stat.h>

typedef struct			s_list
{
	char				*name;
	char				*path;
	char				*full;
	__uint8_t			type;
	struct dirent		*entry;
	struct stat			stats;
	struct s_list		*next;
}						t_list;

typedef struct			s_pparam
{
	int					max_nlink;
	int					max_bsize;
	unsigned int		block_alloc;
}						t_maxp;

int						ft_init_options(char **argv, int *start);
char					*ft_str_to_dir(char const *s1, char const *s2);
void					ft_perror(char *dir_path);
char					*ft_get_time(t_list *list, int opt);
t_list					*ft_list_create(struct dirent *entry,
										struct stat stats, char *path);
t_list					*ft_list_new(t_list *list, struct dirent *entry,
										struct stat stats, char *path);
void					ft_list_print(t_list *list, t_maxp *p, int opt);
char					*ft_get_long_output(t_list *list, t_maxp *p);
void					ft_get_dir(char *dir_path, int opt);
t_maxp					*ft_set_params(t_list *list);
t_list					*ft_sort_ascii(t_list *list);
void					ft_merge(t_list **first, int opt);
void					ft_list_clear(t_list **begin_list);

#endif
