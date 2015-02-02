/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 15:55:22 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/20 11:28:16 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

float	ft_atof(const char *str)
{
	float	res;
	float	sign;
	int		point;

	point = 0;
	res = 0;
	sign = 1;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while (*str)
	{
		if (*str == '.')
			point = 1;
		if ((*str - '0') >= 0 && (*str - '0') <= 9)
		{
			if (point)
				sign = (float)(sign / 10.0);
			res = (float)(res * 10.0 + *str - '0');
		}
		str++;
	}
	return (res * sign);
}
