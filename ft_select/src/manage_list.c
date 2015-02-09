/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:20:02 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/09 14:36:07 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_del_element(t_list *tmp)
{
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	free(tmp);
	tmp = 0;
}

int			ft_display_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	if (list->next == list)
		ft_putendl(tmp->data);
	while (tmp->next != list)
	{
		ft_putendl(tmp->data);
		tmp = tmp->next;
		if (tmp->next == list)
			ft_putendl(tmp->data);
	}
	return (0);
}

void		ft_list_remove(t_param *p, t_list **list, int pos)
{
	t_list	*tmp;

	tmp = (*list);
	if (pos == 0)
		return ;
	if (pos > 0)
	{
		while (pos > 0)
		{
			tmp = tmp->next;
			pos--;
		}
		ft_del_element(tmp);
	}
	p->count -= 1;
}

t_list		*ft_ret_elt(t_list *lst, int pos)
{
	t_list	*tmp;

	tmp = lst;
	while (pos > 0)
	{
		tmp = tmp->next;
		pos -= 1;
	}
	return (tmp);
}
