/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:59:53 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/23 22:56:31 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <unistd.h>

void	ft_display_lst(t_env *lst, char type)
{
	t_env	*tmp;

	if (!lst)
		return ;
	tmp = lst->next;
	while (tmp != lst)
	{
		ft_putstr(tmp->data);
		if ((type != 1 && tmp->next != lst) || type == 0)
			ft_putchar('\n');
		tmp = tmp->next;
	}
}

char	*ft_find_element(t_env *lst, char *value)
{
	t_env	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst->next;
	while (tmp != lst && !ft_strcmp_shell(tmp->data, value, 1))
		tmp = tmp->next;
	if (tmp == lst)
		return (NULL);
	return (&tmp->data[ft_strlen(value) + 1]);
}

void	ft_setenv_list(t_env *lst, char *var, char *value)
{
	ft_remove_element(&lst, var);
	ft_add_element(&lst, value, var);
}
