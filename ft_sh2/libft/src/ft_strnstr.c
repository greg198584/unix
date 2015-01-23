/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:00:09 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/08 09:38:18 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	j;

	if (s2[0] == '\0' || !s2 || !n)
		return ((char *)s1);
	i = 0;
	j = 0;
	while (s1[i] != '\0' && s1 && n--)
	{
		j = (j * (s1[i] == s2[j])) + (s1[i] == s2[j]);
		if (s2[j] == '\0')
			return ((char *)s1 + (i - (j - 1)));
		i++;
	}
	return (NULL);
}
