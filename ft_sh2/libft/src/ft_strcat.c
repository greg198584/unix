/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:11:16 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/07 14:44:20 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	const char	*src_ptr;
	char		*dst_ptr;

	src_ptr = src;
	dst_ptr = dst + ft_strlen(dst);
	*dst_ptr++ = *src_ptr;
	while (*src_ptr++)
		*dst_ptr++ = *src_ptr;
	return (dst);
}
