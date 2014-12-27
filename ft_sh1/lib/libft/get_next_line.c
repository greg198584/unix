/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:35:51 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/17 11:51:52 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static t_param	*gnl_create_param(int fd)
{
	t_param	*p;

	if ((p = (t_param *)ft_memalloc(sizeof(t_param))) == NULL)
		return (NULL);
	p->fd = fd;
	p->next = p;
	p->buff = NULL;
	return (p);
}

static t_param	*gnl_add_param(int fd, t_param *param)
{
	t_param	*p;

	if ((p = (t_param *)ft_memalloc(sizeof(t_param))) == NULL)
		return (NULL);
	p->fd = fd;
	p->next = param->next;
	p->buff = NULL;
	param->next = p;
	return (p);
}

static t_param	*gnl_init_param(int fd, t_param *param)
{
	t_param	*p;

	p = param;
	if (param == NULL)
		param = gnl_create_param(fd);
	else
	{
		while (param->next != NULL)
		{
			if (param->fd == fd)
				break ;
			if (param->next == p)
			{
				param = gnl_add_param(fd, param);
				break ;
			}
			param = param->next;
		}
	}
	return (param);
}

int				get_next_line(int const fd, char **line)
{
	static t_param	*p;
	char			r_buf[BUFF_SIZE + 1];
	char			*tmp;
	int				i;

	p = gnl_init_param(fd, p);
	while (!ft_strchr(p->buff, '\n'))
	{
		if ((i = read(p->fd, r_buf, BUFF_SIZE)) < 1)
			break ;
		r_buf[i] = 0;
		p->buff = (!p->buff) ? ft_strdup(r_buf) : ft_strjoin(p->buff, r_buf);
	}
	if ((tmp = ft_strchr(p->buff, '\n')))
	{
		*line = p->buff;
		p->buff = tmp + 1;
		*tmp = 0;
	}
	else
	{
		*line = p->buff;
		return (0);
	}
	return (1 - (tmp == NULL) * 2);
}
