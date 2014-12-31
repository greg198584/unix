/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 09:40:55 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/31 09:18:19 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnrep(char *str, char *sub, char *rep, char c)
{
	char	**split_sub;
	char	**split_rep;
	int		i;

	i = 0;
	if (ft_strchr(sub, c) == NULL || ft_strchr(rep, c) == NULL)
		return (NULL);
	split_sub = ft_strsplit(sub, c);
	split_rep = ft_strsplit(rep, c);
	while (split_sub[i] != 0 && split_rep[i] != 0)
	{
		str = ft_strrep(str, split_sub[i], split_rep[i], REPLACE_ONCE);
		i++;
	}
	return (str);
}
