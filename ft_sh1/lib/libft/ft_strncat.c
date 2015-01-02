/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 09:43:02 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/07 15:00:47 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	unsigned int	size_src;
	unsigned int	size_dst;

	size_src = ft_strlen(src);
	size_dst = ft_strlen(dst);
	if (size_src < n)
		ft_strcpy(&dst[size_dst], src);
	else
	{
		ft_strncpy(&dst[size_dst], src, n);
		dst[size_dst + n] = '\0';
	}
	return (dst);
}
