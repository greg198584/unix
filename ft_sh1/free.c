/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 16:39:07 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/27 16:40:13 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <stdlib.h>

void	ft_free_arr(char **arr)
{
	int	i;

	i = -1;
	if (arr != NULL)
	{
		while (arr[++i] != NULL)
			free(arr[i]);
		free(arr);
	}
}

void	ft_free_lst(t_env *list)
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
}
