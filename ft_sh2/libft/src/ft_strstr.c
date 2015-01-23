/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:49:54 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/31 09:14:37 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*ptr_s1;
	char		*test;
	size_t		len;

	test = "";
	if (s1 == test && s2 == test)
		return (test);
	ptr_s1 = s1;
	len = ft_strlen(s2);
	while (*ptr_s1)
	{
		if (ft_memcmp (ptr_s1, s2, len) == 0)
			return (char *)ptr_s1;
		ptr_s1++;
	}
	return (NULL);
}
