/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:55:13 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/08 09:28:05 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char			*str;
	unsigned int	i;

	str = ft_memalloc(ft_strlen(s));
	i = -1;
	while (s && *(s + ++i))
		*(str + i) = f(*(char *)(s + i));
	return (str);
}
