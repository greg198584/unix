/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:19:56 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/31 14:06:18 by glafitte         ###   ########.fr       */
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
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	return (tmp);
}

static void		ft_add_list(t_list **list, char *str)
{
	t_list	*tmp;

	tmp = *list;
	if (tmp)
	{
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_element(str);
		tmp->next->prev = tmp;
	}
	else
		*list = ft_create_element(str);
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
	return (list);
}
