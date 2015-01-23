/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:34:46 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/12 09:43:37 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup_2(char const *src, size_t len)
{
	char	*str;

	str = ft_memalloc(len + 1);
	if (str)
	{
		ft_memcpy(str, src, len);
		str[len] = 0;
	}
	return (str);
}

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	return ((s == NULL) ? NULL : ft_strndup_2(s + start, len));
}
