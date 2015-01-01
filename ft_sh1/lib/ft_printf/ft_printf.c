/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 07:48:10 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/23 16:12:52 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int		ft_test(const char *format, int *i, t_size *len)
{
	if (format[*i] == '+')
		ft_putchar('+');
	if (format[*i] == ' ')
		ft_putchar(' ');
	while (format[*i] == '+' || format[*i] == ' ' || format[*i] == '%')
		*i = *i + 1;
	return (0);
}

static void		ft_flag(const char *fmt, int i, va_list ap, t_size *len)
{
	if (fmt[i] == INT_D || fmt[i] == INT_I)
		ft_precision_nbr(va_arg(ap, int), len);
	else if (fmt[i] == STRING_1 || fmt[i] == STRING_2)
		ft_check_string(va_arg(ap, char *), fmt[i], len);
	else if (fmt[i] == CHARAC_1 || fmt[i] == CHARAC_2)
		ft_checking_c(va_arg(ap, int), fmt[i], len);
	else if (fmt[i] == ADRESS)
		ft_putnbr_hexa(ft_strdup("0x7fff"), va_arg(ap, unsigned int), 'x', len);
	else if (fmt[i] == UINT_D || fmt[i] == UINT_U)
		ft_print_uint(va_arg(ap, unsigned int), len);
	else if (fmt[i] == HEXA_1 || fmt[i] == HEXA_2)
		ft_putstr(ft_option_hexa(va_arg(ap, unsigned int), fmt[i], len));
	else if (fmt[i] == OCTAL_1 || fmt[i] == OCTAL_2)
		ft_putstr(ft_option_octal(va_arg(ap, unsigned int), fmt[i], len));
	else
		ft_putchar(fmt[i]);
}

static void		ft_call(const char *format, int *i, va_list ap, t_size *len)
{
	int	y;

	y = 0;
	len->count = -2;
	len->precision = 0;
	*i = *i + 1;
	while (format[*i] == '#' || format[*i] == '-' || format[*i] == '0')
	{
		if (format[*i] == '0' && format[*i + 1] >= '1' && format[*i + 1] <= '9')
		{
			len->precision = ft_atoi(ft_char_to_str(format[*i + 1]));
			len->count = len->precision;
			len->nbr = 0;
			*i = *i + 2;
			break ;
		}
		*i = *i + 1;
	}
	if (format[*i] >= '1' && format[*i] <= '9')
		ft_precision_checking(format, i, len);
	ft_test(format, i, len);
	ft_flag(format, *i, ap, len);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	t_size	*len;
	int		i;

	i = 0;
	if ((len = (t_size *)ft_memalloc(sizeof(t_size))) == NULL)
		return (0);
	va_start(ap, format);
	if (ft_test_big_s(format, i, ap))
		return (0);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
			ft_call(format, &i, ap, len);
		else
		{
			if (format[i] == '%')
				i++;
			ft_putchar(format[i]);
		}
		i++;
	}
	va_end(ap);
	return (len->count += i);
}
