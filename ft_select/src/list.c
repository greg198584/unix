/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:19:56 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/06 10:47:07 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_list	*ft_create_element(char *str)
{
	t_list	*tmp;

	tmp = NULL;
	if ((tmp = malloc(sizeof(t_list))) == NULL)
		ft_puterror("Erreur: allocation memoire");
	if (tmp)
	{
		tmp->data = str;
		tmp->valid = 0;
		tmp->size = ft_strlen(str);
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	return (tmp);
}

void			ft_add_list(t_list **list, char *str)
{
	t_list	*tmp;
	t_list	*head;

	tmp = *list;
	head = tmp;
	if (tmp)
	{
		while(tmp->next != head)
			tmp = tmp->next;
		tmp->next = ft_create_element(str);
		tmp->next->prev = tmp;
		tmp->next->next = head;
		head->prev = tmp->next;
	}
	else
		*list = ft_create_element("----[ ft_select ]----");
}

t_list			*ft_create_list(int argc, char **argv)
{
	t_list	*list;
	int		i;

	i = 0;
	if ((list = malloc(sizeof(t_list))) == NULL)
		ft_puterror("Erreur: allocation memoire. main.c");
	list = NULL;
	while(i++ < argc - 1)
		ft_add_list(&list, argv[i]);
	ft_add_list(&list, "---[ FIN DE LISTE ]---");
	return (list);
}
