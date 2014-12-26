/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 16:33:48 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/26 17:48:38 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <stdlib.h>

void	ft_add_element(t_list **list, char *val, char *start)
{
	t_list	*new;
	int		i;
	int		j;
	int		size;

	if ((new = malloc(sizeof(*new))) == NULL)
		ft_error("Erreur: probleme allocation memoire [ ft_init_list.c ]\n");
	size = (start != NULL) ? ft_strlen(start) : 0;
	if ((new->data = malloc(size + ft_strlen(val) + 1)) == NULL)
		ft_error("Erreur: probleme allocation memoire [ ft_init_list.c ]\n");
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
	new->previous = (*list)->previous;
	new->next = (*list);
	(*list)->previous->next = new;
	(*list)->previous = new;
}

void	ft_remove_element(t_list **list, char *value)
{
	t_list	*tmp;

	tmp = (*list)->next;
	while (tmp != (*list) && !ft_strncmp(tmp->data, value, 1))
		tmp = tmp->next;
	if (tmp != (*list))
	{
		tmp->previous->next = tmp->next;
		tmp->next->previous = tmp->previous;
		free(tmp);
	}
}

t_list		*ft_create_list(char **env)
{
	t_list	*root;
	int		i;

	if ((root = malloc(sizeof(*root))) == NULL)
		ft_error("Erreur: probleme allocation memoire [ ft_init_list.c ]\n");
	root->next = root;
	root->previous = root;
	i = -1;
	while (env[++i])
		ft_add_element(&root, env[i], NULL);
	return (root);
}

char		*ft_find_element(t_list *list, char *value)
{
	t_list	*tmp;

	tmp = list->next;
	while (tmp != list && !ft_strncmp(tmp->data, value, 1))
		tmp = tmp->next;
	if (tmp == list)
		return (NULL);
	return (&tmp->data[ft_strlen(value) + 1]);
}

char		**ft_conv_list(t_list *env)
{
	t_list	*tmp;
	char	**arg;
	int		i;
	int		count;

	count = 0;
	if (env == NULL)
		return (NULL);
	tmp = env->next;
	while (tmp != env)
	{
		++count;
		tmp = tmp->next;
	}
	if ((arg = malloc(sizeof(char *) * (count + 1))) == NULL)
		ft_error("Error: probleme allocation memoire !\n");
	i = -1;
	tmp = env->next;
	while (tmp != env)
	{
		arg[++i] = ft_strdup(tmp->data);
		tmp = tmp->next;
	}
	arg[++i] = NULL;
	return (arg);
}
