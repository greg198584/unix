/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:35:51 by glafitte          #+#    #+#             */
/*   Updated: 2015/04/02 10:45:25 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>

static char ft_getchar(int const fd)
{
	int		ret;
	char	c;

	if ((ret = read(fd, &c, 1)) == 0)
		return (0);
	return ((ret < 0) ? -1 : c);
}

int			ft_gnl(int const fd, char **line)
{
	char	*dst;
	char	*buf;
	char	*end;
	int		c;

	if (!line || fd < 0 || !(dst = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	buf = dst;
	end = buf + BUFF_SIZE - 1;
	while ((c = ft_getchar(fd)) != 0 && c != 10 && buf < end)
	{
		if (c == -1)
			return (-1);
		*buf++ = c;
	}
	*buf = 0;
	*line = ft_strdup(dst);
	free(dst);
	return (c || ft_strlen(buf) || ft_strlen(*line));
}
