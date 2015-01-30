/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:20:02 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/30 17:31:51 by glafitte         ###   ########.fr       */
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

void ft_list_remove(t_list **begin_list, char *data_ref)
{
	t_list *list_ptr;

	list_ptr = *begin_list;
	while (list_ptr)
	{
		if (ft_strcmp(list_ptr->data, data_ref) == 0)
			list_ptr->next = list_ptr->next->next;
		free(list_ptr);
	}
	list_ptr = list_ptr->next;
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
