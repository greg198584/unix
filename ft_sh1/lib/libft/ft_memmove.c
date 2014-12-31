/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:53:33 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/06 08:49:39 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest_ptr;
	const char	*src_ptr;

	dest_ptr = dst;
	src_ptr = src;
	if (src_ptr <= dest_ptr)
	{
		dest_ptr += len - 1;
		src_ptr += len - 1;
		while (len--)
			*dest_ptr-- = *src_ptr--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
