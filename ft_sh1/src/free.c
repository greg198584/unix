/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 16:39:07 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/01 11:47:39 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <stdlib.h>

int		ft_free_arg(char **arg)
{
	int	i;

	i = -1;
	if (arg != NULL)
	{
		while (arg[++i] != NULL)
			free(arg[i]);
		free(arg);
	}
	return (1);
}

int		ft_free_list(t_env *list)
{
	t_env	*tmp;
	t_env	*next;

	tmp = list->next;
	while (tmp != list)
	{
		next = tmp->next;
		free(tmp->data);
		free(tmp);
		tmp = next;
	}
	free(list);
	return (1);
}
