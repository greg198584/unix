/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/21 13:45:59 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/19 11:14:27 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_precision_checking(const char *format, int *i, t_size *len)
{
	int	y;

	y = 0;
	if ((len->pl = (char *)malloc(sizeof(char) * 1024)) == NULL)
		return (-1);
	len->pl[y++] = format[*i];
	*i = *i + 1;
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		len->pl[y] = format[*i];
		*i = *i + 1;
		y++;
	}
	len->precision = ft_atoi(len->pl);
	return (0);
}

int	ft_precision_nbr(int i, t_size *len)
{
	int		y;
	int		negativ;
	char	*str;

	y = -1;
	negativ = 0;
	len->count += ft_strlen(ft_itoa(i));
	if (i < 0 && len->precision < 10)
	{
		ft_putchar('-');
		negativ = 1;
	}
	while (y++ < len->precision - ft_strlen(ft_itoa(i)))
	{
		if (len->precision > 9)
			ft_putchar(' ');
		else
			ft_putchar('0');
	}
	str = ft_itoa(i);
	if (negativ == 1)
		ft_putstr(ft_strchr(str, '-') + 1);
	else
		ft_putstr(str);
	return (0);
}

int	ft_print_precision(t_size *len, int size)
{
	int	y;

	y = 0;
	while (y < len->precision - size)
	{
		if (len->precision > 9)
			ft_putchar(' ');
		else
			ft_putchar('0');
		y++;
	}
	return (0);
}
