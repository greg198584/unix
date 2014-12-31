/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 09:58:55 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/23 16:17:15 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

static char	*g_str_save;

int			ft_check_string(char *str, char option, t_size *len)
{
	int	y;

	y = 0;
	if (option == 's')
		ft_putstr_and_precision(str, len);
	if (option == 'S')
	{
		while (y < len->precision - 1)
		{
			if (len->precision > 9)
				ft_putchar(' ');
			else
				ft_putchar('0');
			y++;
		}
		ft_putstr(g_str_save);
		ft_strclr(g_str_save);
	}
	return (1);
}

int			ft_checking_c(char c, char option, t_size *len)
{
	if (option == 'c')
	{
		ft_print_precision(len, 1);
		ft_putchar(c);
		len->count += 1;
	}
	if (option == 'C')
	{
		ft_putstr(g_str_save);
		len->count += ft_strlen(g_str_save);
		ft_strclr(g_str_save);
	}
	return (0);
}

static	int	ft_check_string_test(char *str)
{
	int			i;
	int			special_char;

	i = 0;
	special_char = 0;
	while (str[i] != '\0')
	{
		if (ft_isprint(str[i]))
			i++;
		else
		{
			special_char++;
			i++;
		}
	}
	if (special_char == 0)
	{
		g_str_save = ft_strdup(str);
		return (0);
	}
	else
		return (1);
}

int			ft_test_big_c(char c)
{
	char	*str;

	str = ft_char_to_str(c);
	if (ft_check_string_test(str))
		return (1);
	else
		return (0);
}

int			ft_test_big_s(const char *fmt, int i, va_list ap)
{
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			while (fmt[i] == '#' || fmt[i] == '0' || fmt[i] == '-' ||
					fmt[i] == '+' || fmt[i] == ' ')
				i++;
			if (fmt[i] == 'S')
			{
				if (ft_check_string_test(va_arg(ap, char *)))
					return (1);
				else
					return (0);
			}
			if (fmt[i] == 'C')
			{
				if (ft_test_big_c(va_arg(ap, int)))
					return (1);
				else
					return (0);
			}
		}
		i++;
	}
	return (0);
}
