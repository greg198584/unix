/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:20:02 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/22 20:23:26 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_display_list(t_list *list)
{
	if (!list)
		ft_puterror("erreur: liste vide, fin du programme");
	while (list)
	{
		ft_putendl(list->data);
		list = list->next;
	}
	return (0);
}
