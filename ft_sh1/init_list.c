/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:59:06 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/27 16:56:30 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>
#include <ft_sh1.h>

void	ft_add_elt(t_env **list, char *val, char *start)
{
	t_env	*new;
	int		i;
	int		j;
	int		size;

	if ((new = malloc(sizeof(*new))) == NULL)
		ft_puterror("error: problem to malloc the t_list in my_list.c: l30!\n");
	size = (start != NULL) ? ft_strlen(start) : 0;
	if ((new->data = malloc(size + ft_strlen(val) + 1)) == NULL)
		ft_puterror("error: problem to malloc in my_list.c: l33!\n");
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
	new->prec = (*list)->prec;
	new->next = (*list);
	(*list)->prec->next = new;
	(*list)->prec = new;
}

t_env	*ft_create_list(char **env)
{
	t_env	*root;
	int		i;

	if ((root = malloc(sizeof(*root))) == NULL)
		ft_puterror("error: problem to malloc the t_list in my_list.c: l60!\n");
	root->next = root;
	root->prec = root;
	i = -1;
	while (env[++i])
		ft_add_elt(&root, env[i], NULL);
	return (root);
}

void	ft_remove_elt(t_env **lst, char *value)
{
	t_env	*tmp;

	tmp = (*lst)->next;
	while (tmp != (*lst) && !ft_strncmp(tmp->data, value, 1))
		tmp = tmp->next;
	if (tmp != (*lst))
	{
		tmp->prec->next = tmp->next;
		tmp->next->prec = tmp->prec;
		free(tmp);
	}
}
