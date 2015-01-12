/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:35:56 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/02 18:46:53 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE	0x2323

# include "../lib/libft/libft.h"

typedef struct		s_gnlp
{
	int				fd;
	char			*buf;
	struct s_gnlp	*next;
}					t_gnlp;

int					get_next_line(int const fd, char **line);

#endif
