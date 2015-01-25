/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:00:08 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/24 10:31:05 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1++ == *s2++)
		if (*(s1 - 1) == '\0')
			return (0);
	return (*(unsigned char *)(s1 - 1) - *(unsigned char *)(s2 - 1));
}
