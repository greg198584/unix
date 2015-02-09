/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 10:20:51 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/09 14:43:18 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_recup_signal(int signal)
{
	(void)signal;
}

int			ft_ret_resize(t_param *p)
{
	t_winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	p->width = w.ws_row;
	p->height = w.ws_col;
	return (0);
}

void		ft_refresh_buff(t_param *p)
{
	int	i;

	i = -1;
	while (++i < 4)
		p->buffer[i] = 0;
}
