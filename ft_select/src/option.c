/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 17:59:40 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/30 17:05:05 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_remove(t_param *p, t_list *list, t_termios *term)
{
	(void)term;
	//ft_printf("[ mot a supprimer : [%s]\n", ft_ret_elt(list, p->pos.y)->data);
	ft_list_remove(list, ft_ret_elt(list, p->pos.y)->data);
	//ft_clear_screen();
	//ft_display_list(list);
	//ft_exit(p, list, term);
	return (0);
}

int	ft_exit(t_param *p, t_list *list, t_termios *term)
{
	(void)p;
	(void)list;

	ft_putendl("fermeture du programme");
	if((ft_clear_term(term)) == -1)
		ft_puterror("Erreur: lors du retablissement du terminal");
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_check_mov(t_param *p, t_list *list, t_termios *term)
{
	if (p->buffer[0] == 27 && p->buffer[1] == '[' && p->buffer[2] == 'A' ||
			p->buffer[2] == 'B')
	{
		ft_move_cursor(p->pos.y);
		if (!p->value)
			ft_init_value(p, list);
		if (p->buffer[2] == 'A')
			ft_init_down(p, list);
		else if (p->buffer[2] == 'B')
			ft_init_up(p, list);
		ft_manage_line(ft_ret_elt(list, p->pos.y)->data, p->pos.y, 0, 1);
	}
	return (0);
}

int	ft_space(t_param *p, t_list *lst, t_termios *term)
{
	lst->valid = !ft_ret_elt(lst, p->pos.y)->valid == 0 ? lst->valid - 1 :
		lst->valid + 1;
	ft_ret_elt(lst, p->pos.y)->valid = !ft_ret_elt(lst, p->pos.y)->valid;
	ft_manage_line(ft_ret_elt(lst, p->pos.y)->data,
			p->pos.y, ft_ret_elt(lst, p->pos.y)->valid, 0);
	p->pos.y = p->pos.y < p->count ? p->pos.y + 1 : 0;
	ft_manage_line(ft_ret_elt(lst, p->pos.y)->data,
			p->pos.y, ft_ret_elt(lst, p->pos.y)->valid, 1);
	return (0);
}
