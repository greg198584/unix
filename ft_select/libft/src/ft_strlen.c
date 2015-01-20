/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:01:54 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/19 14:05:44 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <string.h>

int	ft_strlen(const char *str)
{
	const char				*p;
	const unsigned long		*lp;
	int						x;

	p = str;
	while ((uintptr_t)p & (sizeof(long) - 1))
		if (*p++ == '\0')
			return ((p - 1) - str);
	lp = (const unsigned long *)p;
	while (1)
		if ((*lp++ - 0x0101010101010101) & 0x8080808080808080)
		{
			x = -1;
			p = (const char *)(lp - 1);
			while (++x < 8)
			{
				while (1)
				{
					if (!p[x])
						return (p - str + x);
					break ;
				}
			}
		}
	return (0);
}
