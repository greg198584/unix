/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:53:33 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/30 18:38:34 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const unsigned char *s;
	unsigned char		*d;
	char				temp[n];
	size_t				i;

	i = -1;
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (++i < n)
		*(temp + i) = *(s + i);
	i = -1;
	while (++i < n)
		*(d + i) = *(temp + i);
	return (dst);
}
