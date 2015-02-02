/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 21:25:08 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/02 16:26:52 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_init_value(t_param *p, t_list *list)
{
	ft_line(ft_ret_elt(list, p->pos.y)->data, p->pos.y,
			ft_ret_elt(list, p->pos.y)->valid, 0);
	p->value = 1;
}

void	ft_init_down(t_param *p, t_list *list)
{
	ft_line(ft_ret_elt(list, p->pos.y)->data, p->pos.y,
			ft_ret_elt(list, p->pos.y)->valid, 0);
	p->pos.y =  p->pos.y == 0 ? p->count : p->pos.y - 1;
	p->value = 1;
}

void	ft_init_up(t_param *p, t_list *list)
{
	ft_line(ft_ret_elt(list, p->pos.y)->data, p->pos.y,
			ft_ret_elt(list, p->pos.y)->valid, 0);
	p->pos.y = p->pos.y < p->count ? p->pos.y + 1 : 0;
	p->value = 1;
}
