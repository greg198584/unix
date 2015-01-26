/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 11:11:20 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/26 12:51:06 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_keyboard ft_touch[]=
{
	{&ft_exit, 4},
	{&ft_exit, 3},
	{&ft_space, 32},
	{&ft_check_mov, 27},
	{NULL, -1}
};

int	ft_check(t_param *p, t_list *list, t_termios *term)
{
	int		res;
	int 	i;

	i = -1;
	ft_hide_cursor();
	//ft_visible_cursor();
	while (1)
	{
		ft_signal(p);
		read(0, p->buffer, 4);
		while (ft_touch[++i].key != -1)
		{
			if (i == 5)
				i = 0;
			if (ft_touch[i].key == p->buffer[0])
				res = (ft_touch[i].func_ptr(p, list, term));
		}
	}
return (0);
}
