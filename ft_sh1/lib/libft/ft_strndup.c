/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 08:56:58 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/19 08:57:39 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *src, size_t len)
{
	char	*str;

	str = (char *)ft_memalloc(len + 1);
	if (str)
	{
		ft_memcpy(str, src, len);
		str[len] = 0;
	}
	return (str);
}
