/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:18:41 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/12 09:44:09 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_strlensplit(char const *s, char c)
{
	int		index;
	int		length;

	index = 0;
	length = 0;
	if (!s)
		return (0);
	while (s[index] == c)
		index++;
	while (s[index])
	{
		if (index == 0)
		{
			if (s[index] != c)
				length++;
		}
		else if (s[index] != c && s[index - 1] == c)
			length++;
		index++;
	}
	return (length);
}

static int		ft_strlenwordsplit(const char *s, char c, int index)
{
	int		length;

	length = 0;
	while (s[index] && s[index] != c)
	{
		length++;
		index++;
	}
	return (length);
}

static char		*ft_next_wordsplit(char const *s, char c, int *index)
{
	char	*word;
	int		size;
	int		index2;

	while (s[*index] == c)
		*index += 1;
	size = ft_strlenwordsplit(s, c, *index);
	if ((word = (char *)malloc(sizeof(*word) * (size + 1))) == NULL)
		return (NULL);
	index2 = 0;
	while (index2 < size)
	{
		word[index2] = s[*index];
		*index += 1;
		index2++;
	}
	word[index2] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		size_tab;
	int		index;
	int		tab_index;

	size_tab = ft_strlensplit(s, c);
	tab = NULL;
	if ((tab = (char **)malloc((size_tab + 1) * sizeof(*tab))) == NULL)
		return (NULL);
	index = 0;
	tab_index = 0;
	while (tab_index < size_tab)
	{
		tab[tab_index] = ft_next_wordsplit(s, c, &index);
		tab_index++;
	}
	tab[tab_index] = NULL;
	return (tab);
}
