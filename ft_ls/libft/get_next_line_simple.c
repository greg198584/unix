/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_simple.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:35:51 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/15 14:44:34 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		get_next_line_simple(int const fd, char **line)
{
	static char	*buff;
	char		r_buf[BUFF_SIZE + 1];
	char		*tmp;
	int			i;

	while (!ft_strchr(buff, '\n'))
	{
		if ((i = read(fd, r_buf, BUFF_SIZE)) < 1)
			break ;
		r_buf[i] = 0;
		buff = (!buff) ? ft_strdup(r_buf) : ft_strjoin(buff, r_buf);
	}
	if ((tmp = ft_strchr(buff, '\n')))
	{
		*line = buff;
		buff = tmp + 1;
		*tmp = 0;
	}
	else
	{
		*line = buff;
		return (0);
	}
	return (1 - (tmp == NULL) * 2);
}
