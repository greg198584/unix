/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:20:02 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/31 13:51:22 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_display_list(t_list *list)
{
	while (list)
	{
		ft_putendl(list->data);
		list = list->next;
	}
	return (0);
}

void	ft_list_remove(t_list *list, int pos)
{
		t_list	*tmp;

		tmp = list->next;
		while (pos > 0)
		{
			tmp = tmp->next;
			pos -= 1;
		}
		list->valid -= tmp->valid;
		list->size -= 1;
		free(tmp);
}

t_list	*ft_ret_elt(t_list *lst, int pos)
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
