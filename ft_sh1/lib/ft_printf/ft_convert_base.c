/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 09:43:04 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/12 12:45:09 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		convert;
	char	*res;

	i = 0;
	res = ft_strnew(65);
	convert = ft_atoi_base(nbr, base_from);
	while (convert > 0)
	{
		res[i++] = base_to[convert % ft_strlen(base_to)];
		convert /= ft_strlen(base_to);
	}
	res[i] = '\0';
	return (ft_strrev(res));
}
