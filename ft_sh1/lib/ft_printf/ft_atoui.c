/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int_conversion.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 16:36:14 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/23 13:06:32 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_atoui(char *str, unsigned int i)
{
	unsigned int	number;
	unsigned int	negativ;
	unsigned int	max_value;

	number = 0;
	negativ = 0;
	max_value = 4294967295;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		negativ = 1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += ((int)str[i] - '0');
		i++;
	}
	if (!(number < 4294967295))
		return (1);
	if (negativ == 1)
		return (max_value - number);
	return (number);
}
