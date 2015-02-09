/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 17:59:40 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/09 14:30:23 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_exit(t_param *p, t_list *list, t_termios *term)
{
	(void)p;
	(void)list;
	ft_visible_cursor();
	ft_putendl("fermeture du programme");
	if ((ft_clear_term(p)) == -1)
		ft_puterror("Erreur: lors du retablissement du terminal");
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_enter(t_param *p, t_list *list, t_termios *term)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = list->next;
	ft_clear_area();
	i = 0;
	ft_putendl("--> [ liste selectionner ] <---\n");
	while (i < p->count + 1)
	{
		if (tmp->valid)
		{
			ft_printf("[%s]  ", tmp->data);
			p->nb_elt += 1;
		}
		tmp = tmp->next;
		i++;
	}
	if (p->nb_elt == 0)
		ft_putstr("Aucun element selectionner");
	ft_putendl("\n\n-------------------------------");
	ft_exit(p, list, term);
}

int	ft_del(t_param *p, t_list *list, t_termios *term)
{
	ft_list_remove(p, &list, p->pos.y);
	p->pos.y = p->pos.y < p->count ? p->pos.y + 0 : 0;
	ft_clear_area();
	ft_display_list(list);
	ft_line(ft_ret_elt(list, p->pos.y)->data, p->pos.y,
			ft_ret_elt(list, p->pos.y)->valid, 1);
}

int	ft_move(t_param *p, t_list *list, t_termios *term)
{
	if (p->buffer[0] == 27 && p->buffer[1] == 0)
	{
		ft_clear_area();
		ft_exit(p, list, term);
	}
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
		ft_line(ft_ret_elt(list, p->pos.y)->data, p->pos.y,
				ft_ret_elt(list, p->pos.y)->valid, 1);
		ft_refresh_buff(p);
	}
	return (0);
}

int	ft_space(t_param *p, t_list *lst, t_termios *term)
{
	lst->valid = !ft_ret_elt(lst, p->pos.y)->valid == 0 ? lst->valid - 1 :
		lst->valid + 1;
	ft_ret_elt(lst, p->pos.y)->valid = !ft_ret_elt(lst, p->pos.y)->valid;
	ft_line(ft_ret_elt(lst, p->pos.y)->data,
			p->pos.y, ft_ret_elt(lst, p->pos.y)->valid, 1);
	p->pos.y = p->pos.y < p->count - 1 ? p->pos.y + 1 : 0;
	return (0);
}
