/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:55:50 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/06 08:49:25 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_ptr;
	const unsigned char	*s2_ptr;

	s1_ptr = s1;
	s2_ptr = s2;
	while (n--)
	{
		if (*s1_ptr != *s2_ptr)
		{
			if (*s1_ptr < *s2_ptr)
				return (-1);
			else
				return (1);
		}
		s1_ptr++;
		s2_ptr++;
	}
	return (0);
}
