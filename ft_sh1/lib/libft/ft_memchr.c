/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:33:48 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/06 08:49:47 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *s_ptr;

	s_ptr = s;
	while (n--)
	{
		if (*s_ptr == c)
			return ((void *)s_ptr);
		s_ptr++;
	}
	return (NULL);
}
