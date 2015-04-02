/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 10:09:33 by glafitte          #+#    #+#             */
/*   Updated: 2015/04/02 11:24:24 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"
#include <stdlib.h>

t_env	*ft_create_list(char **env)
{
	t_env	*root;
	int		i;

	if ((root = malloc(sizeof(*root))) == NULL)
		ERR_LOC("allocation memoire");

	return (root);
}
