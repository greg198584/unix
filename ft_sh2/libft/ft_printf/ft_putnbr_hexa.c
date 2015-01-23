/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 15:46:50 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/19 11:42:07 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

unsigned int	ft_putnbr_hexa(char *str, unsigned int nb, char option,
								t_size *len)
{
	len->count += ft_strlen(str);
	if (len->precision != 0)
		ft_print_precision(len, (ft_strlen(ft_uitoa(nb)) + ft_strlen(str) - 2));
	ft_putstr(str);
	len->precision = 0;
	if (nb >= 16)
		ft_putnbr_hexa("", nb / 16, option, len);
	if (nb % 16 < 10)
	{
		ft_putchar_fd(nb % 16 + 48, 0);
		len->count += 1;
	}
	else
	{
		ft_putchar_fd(nb % 16 + option - 33, 0);
		len->count += 1;
	}
	return (nb);
}
