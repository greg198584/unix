/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:43:41 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/19 11:43:43 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

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
