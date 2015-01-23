/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:33:23 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/31 09:12:09 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while (ft_isspace(*(s + i)))
		i++;
	j = ft_strlen(s);
	while (ft_isspace(s[j - 1]))
		j--;
	str = ft_strsub(s, i, (j != 0) ? j -= i : j);
	if (str == NULL)
		return (NULL);
	return (str);
}
