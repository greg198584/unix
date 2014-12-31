/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:33:48 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/30 14:36:28 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!(void *)s || n == 0)
		return (NULL);
	if (n)
	{
		if (*((unsigned char *)s) == (unsigned char)c)
			return ((void *)s);
		else
			return (ft_memchr(++s, c, --n));
	}
	return (NULL);
}
