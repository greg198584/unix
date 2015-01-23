/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:52:50 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/08 09:34:14 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char	*srcc;
	char		*dstt;
	size_t		i;

	srcc = src;
	dstt = dst;
	i = n;
	while (i-- > 0)
		if ((*dstt++ = *srcc++) == c)
			return (dstt);
	return (NULL);
}
