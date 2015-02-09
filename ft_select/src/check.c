/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 11:11:20 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/09 14:28:07 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_keyboard g_touch[] =
{
	{&ft_exit, 4},
	{&ft_exit, 3},
	{&ft_space, 32},
	{&ft_move, 27},
	{&ft_del, 127},
	{&ft_enter, '\n'},
	{NULL, -1}
};

int	ft_check(t_param *p, t_list *list, t_termios *term)
{
	int	res;
	int	i;

	i = -1;
	ft_hide_cursor();
	while (1)
	{
		ft_ret_resize(p);
		read(0, p->buffer, 3);
		while (g_touch[++i].key != -1)
		{
			if (p->count == 0)
			{
				ft_clear_area();
				ft_puterror("Erreur: votre liste est maintenant vide !");
			}
			if (i == 7)
				i = 0;
			if (g_touch[i].key == p->buffer[0])
				res = (g_touch[i].func_ptr(p, list, term));
		}
		ft_ret_resize(p);
	}
	return (0);
}
