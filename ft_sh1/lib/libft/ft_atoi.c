/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:57:08 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/03 16:57:40 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	number;
	int	negativ;

	i = 0;
	number = 0;
	negativ = 0;
	while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\r')
			|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\t'))
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
	if (negativ == 1)
		return (-number);
	else
		return (number);
}
