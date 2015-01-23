/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 16:08:35 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/23 22:57:04 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <stdlib.h>

static int	ft_strlen_wp(const char *str, char end, char end1)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != end && str[i] != end1)
		i++;
	return (i);
}

static	int	ft_nbr_words(const char *str, char end, char end1)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] && (str[i] == end || str[i] == end1))
			++i;
		count = (str[i] && str[i] != end && str[i] != end1) ? count + 1 : count;
		while (str[i] && str[i] != end && str[i] != end1)
			++i;
		i = str[i] == '\0' ? i : i + 1;
	}
	return (count);
}

static	int	ft_strdup_wp(char *cpy, const char *src, char end, char end1)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (src[j] && (src[j] == end || src[j] == end1))
		++j;
	while (src[j] && src[j] != end && src[j] != end1)
	{
		cpy[++i] = src[j];
		j++;
	}
	cpy[++i] = '\0';
	return (j);
}

char		**ft_str_to_wordtab(char *path, char end, char end1)
{
	char	**array;
	int		size;
	int		i;
	int		j;

	size = ft_nbr_words(path, end, end1);
	if (size == 0)
		return (NULL);
	if ((array = malloc(sizeof(char *) * (size + 1))) == NULL)
		ft_puterror("erreur: allocation memoire tool.c ligne 73\n");
	i = 0;
	j = -1;
	while (path[i])
	{
		if ((array[++j] = malloc(sizeof(char) *
			ft_strlen_wp(&path[i], end, end1)))
				== NULL)
			ft_puterror("erreur: allocation memoire tool.c ligne 80\n");
		i += ft_strdup_wp(array[j], &path[i], end, end1);
		i = (path[i] == '\0') ? i : i + 1;
	}
	array[++j] = NULL;
	return (array);
}
