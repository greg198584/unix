/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 17:59:40 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/31 14:16:05 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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

int	ft_del(t_param *p, t_list *list, t_termios *term)
{
	t_list	*after;
	int		j;
	char	*last;

	j = -1;
	if (list->size == 0)
		ft_exit(p, list, term);
	last = ft_ret_elt(list, p->pos.y)->next == list ? list->prev->data : NULL;
	ft_clear_list(list, p->pos.y);
	ft_list_remove(list, p->pos.y);
	after = list->next;
	while (++j < p->pos.y)
		after = after->next;
	while (after != list)
	{
		ft_line(after->data, j, after->valid, j == p->pos.y ? 1 : 0);
		after = after->next;
		j += 1;
	}
	if (last)
	{
		ft_delete_char(j, ft_strlen(last));
		ft_line(list->prev->data, j - 1, list->prev->valid, 1);
	}
	p->pos.y = last ? p->pos.y - 1 : p->pos.y;
}

int	ft_move(t_param *p, t_list *list, t_termios *term)
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
		ft_line(ft_ret_elt(list, p->pos.y)->data, p->pos.y, 0, 1);
	}
	return (0);
}

int	ft_space(t_param *p, t_list *lst, t_termios *term)
{
	lst->valid = !ft_ret_elt(lst, p->pos.y)->valid == 0 ? lst->valid - 1 :
		lst->valid + 1;
	ft_ret_elt(lst, p->pos.y)->valid = !ft_ret_elt(lst, p->pos.y)->valid;
	ft_line(ft_ret_elt(lst, p->pos.y)->data,
			p->pos.y, ft_ret_elt(lst, p->pos.y)->valid, 0);
	p->pos.y = p->pos.y < p->count ? p->pos.y + 1 : 0;
	ft_line(ft_ret_elt(lst, p->pos.y)->data,
			p->pos.y, ft_ret_elt(lst, p->pos.y)->valid, 1);
	return (0);
}
