/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/25 16:33:48 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/25 16:55:39 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <stdlib.h>

static void	ft_add_elt(t_list **list, char *val, char *start)
{
	t_list	*new;
	int		i;
	int		j;
	int		size;

	if ((new = malloc(sizeof(*new))) == NULL)
		ft_error("error: problem to malloc the t_list in my_list.c: l30!\n");
	size = (start != NULL) ? ft_strlen(start) : 0;
	if ((new->data = malloc(size + my_strlen(val) + 1)) == NULL)
		ft_error("error: problem to malloc in my_list.c: l33!\n");
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

t_list		*ft_create_list(char **env)
{
	t_list	*root;
	int		i;

	if ((root = malloc(sizeof(*root))) == NULL)
		my_puterror("error: problem to malloc the t_list in my_list.c: l60!\n");
	root->next = root;
	root->prec = root;
	i = -1;
	while (env[++i])
		my_add_elt(&root, env[i], NULL);
	return (root);
}
