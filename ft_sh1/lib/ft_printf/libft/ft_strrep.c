/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 11:24:05 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/30 20:49:25 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *s1, const char *s2)
{
	size_t	len;
	char	*str;

	if (*s2 == '\0')
		return ((char *)s1);
	str = (char *)s1;
	len = ft_strlen(s2);
	while (*str)
	{
		if (*str++ == *s2)
		{
			if (!ft_strncmp((const char *)(str - 1), s2, len) == 0)
				return (str - 1);
		}
	}
	return (NULL);
}
