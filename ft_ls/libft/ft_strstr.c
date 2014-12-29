/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:49:54 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/06 16:02:42 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*ptr_s1;
	size_t		len;

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
