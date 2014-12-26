/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 15:16:21 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/26 19:27:49 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <stdlib.h>

void	ft_free_arg(char **arg)
{
	int	i;

	i = -1;
	if (arg != NULL)
	{
		while (arg[++i] != NULL)
			free(arg[i]);
		free(arg);
	}
}

void	ft_setenv_list(t_list *list, char *var, char *value)
{
	ft_remove_element(&list, var);
	ft_add_element(&list, value, var);
}

void	ft_free_list(t_list *list)
{
	t_list	*tmp;
	t_list	*next;

	tmp = list->next;
	while (tmp != list)
	{
		next = tmp->next;
		free(tmp->data);
		free(tmp);
		tmp = next;
	}
	free(list);
}
