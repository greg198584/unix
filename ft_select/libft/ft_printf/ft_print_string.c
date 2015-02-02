/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 09:33:02 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/19 14:27:12 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <string.h>

int	ft_putstr_and_precision(char *str, t_size *len)
{
	int	y;

	if (!str)
		return (0);
	y = 0;
	while (y < len->precision - ft_strlen(str))
	{
		if (len->precision > 9)
			ft_putchar(' ');
		else
			ft_putchar('0');
		y++;
	}
	ft_putstr(str);
	len->count += ft_strlen(str);
	return (0);
}
