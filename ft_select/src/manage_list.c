/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:20:02 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/25 21:22:30 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_display_list(t_list *list)
{
	while (list)
	{
		ft_putendl(list->data);
		list = list->next;
	}
	return (0);
}

void	ft_remove_element(t_list **lst, char *value)
{
	t_list	*tmp;

	tmp = (*lst)->next;
	while (tmp != (*lst) && !ft_cmp_elem(tmp->data, value, 1))
		tmp = tmp->next;
	if (tmp != (*lst))
	{
		tmp->next = tmp->next;
		free(tmp);
	}
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
