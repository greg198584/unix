/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:35:51 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/19 11:35:22 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>

static t_gnlp		*gnl_create_param(int fd)
{
	t_gnlp			*p;

	if ((p = (t_gnlp *)malloc(sizeof(t_gnlp))) == NULL)
		return (NULL);
	p->fd = fd;
	p->next = p;
	p->buf = NULL;
	return (p);
}

static t_gnlp		*gnl_add_param(int fd, t_gnlp *param)
{
	t_gnlp			*p;

	if ((p = (t_gnlp *)malloc(sizeof(t_gnlp))) == NULL)
		return (NULL);
	p->fd = fd;
	p->next = param->next;
	p->buf = NULL;
	param->next = p;
	return (p);
}

static t_gnlp		*gnl_init_param(int fd, t_gnlp *param)
{
	t_gnlp			*p;

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

int					get_next_line(int const fd, char **line)
{
	static t_gnlp	*p;
	char			read_buf[BUFF_SIZE + 1];
	char			*tmp;
	int				r;

	p = gnl_init_param(fd, p);
	while (!ft_strchr(p->buf, '\n') && line)
	{
		if ((r = read(p->fd, read_buf, BUFF_SIZE)) < 1)
			break ;
		read_buf[r] = 0;
		p->buf = (!p->buf) ? ft_strdup(read_buf) : ft_strjoin(p->buf, read_buf);
	}
	if ((tmp = ft_strchr(p->buf, '\n')) != NULL && line)
	{
		*line = p->buf;
		p->buf = tmp + 1;
		*tmp = '\0';
		return (1);
	}
	else if (line)
		*line = p->buf;
	return ((!line) ? -1 : r);
}
