/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 07:48:10 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/12 09:42:54 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

unsigned int	ft_putnbr_hexa(unsigned int nb, char option)
{
	if (nb >= 16)
		ft_putnbr_hexa(nb / 16, option);
	if (nb % 16 < 10)
		ft_putchar_fd(nb % 16 + 48, 0);
	else
		ft_putchar_fd(nb % 16 + option - 33, 0);
	return (nb);
}

void			ft_flag(const char *fmt, int i, va_list ap)
{
	if (fmt[i] == 'd')
		ft_putnbr(va_arg(ap, int));
	else if (fmt[i] == 'c')
		ft_putchar(va_arg(ap, int));
	else if (fmt[i] == 's')
		ft_putstr(va_arg(ap, char *));
	else if (fmt[i] == 'p')
	{
		ft_putstr("0x7fff");
		ft_putnbr_hexa(va_arg(ap, unsigned int), 'x');
	}
	else
		ft_putchar(fmt[i]);
}

int				ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			ft_flag(fmt, i, ap);
		}
		else
			ft_putchar(fmt[i]);
		i++;
	}
	va_end(ap);
	return (0);
}
