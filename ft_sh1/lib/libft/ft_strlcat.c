/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:18:14 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/06 08:51:06 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	len;
	size_t	src_len;
	size_t	i;

	len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (len > n)
		return (n + src_len);
	i = 0;
	while ((i + len < n - 1) && src[i])
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (len + src_len);
}
