/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 10:09:33 by glafitte          #+#    #+#             */
/*   Updated: 2015/04/03 13:09:10 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"
#include <stdlib.h>

void	ft_add_element(t_env **list, char *val, char *start)
{
	t_env	*new;
	int		i;
	int		j;
	int		s;

	if ((new = malloc(sizeof(*new))) == NULL)
		ERR_LOC("allocation memoire !");
	s = (start != NULL ? ft_strlen(start) : 0);
	if ((new->data = malloc(sizeof(char) * (s + ft_strlen(val) + 1))) == NULL)
		ERR_LOC("allocation memoire");
	j = -1;
	i = -1;
	while (start != NULL && start[++i])
		new->data[++j] = start[i];
	i = -1;
	if (j != -1)
		new->data[++j] = '=';
	while (val[++i])
		new->data[++j] = val[i];
	new->data[++j] = '\0';
	new->prev = (*list)->prev;
	new->next = (*list);
	(*list)->prev->next = new;
	(*list)->prev = new;
}

t_env	*ft_create_list(char **env)
{
	t_env	*root;
	int		i;

	if ((root = malloc(sizeof(*root))) == NULL)
		ERR_LOC("allocation memoire !");
	root->next = root;
	root->prev = root;
	i = -1;
	while (env[++i])
		ft_add_element(&root, env[i], NULL);
	return (root);
}

void	ft_remove_elem(t_env **list, char *value)
{
	t_env	*tmp;

	tmp = (*list)->next;
	while (tmp != (*list) && !ft_strcmp_sh(tmp->data, value, 1))
		tmp = tmp->next;
	if (tmp != (*list))
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		free(tmp);
	}
}
