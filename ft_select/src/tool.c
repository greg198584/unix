/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 10:20:51 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/06 11:14:28 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_recup_signal(int signal)
{
	(void)signal;
	return ;
}

int			ft_signal(t_param *p)
{
	t_winsize	w;

	signal(SIGWINCH, SIG_IGN);
	ioctl(0, TIOCGWINSZ, &w);
	p->width = w.ws_row;
	p->height = w.ws_col;
	signal(SIGWINCH, ft_recup_signal);
	return (0);
}

void		ft_refresh_buff(t_param *p)
{
	int	i;

	i = -1;
	while (++i < 4)
		p->buffer[i] = 0;
}
