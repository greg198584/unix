/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 12:07:01 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/19 11:15:36 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static unsigned int	ft_atoui_base(char *s, char *base)
{
	unsigned int	abs;
	unsigned int	total;

	while (ft_isspace(*s))
		s++;
	abs = 1;
	if (*s == '-')
		abs = -1 * (*s++ == '-');
	else if (*s == '+')
		s++;
	total = 0;
	while (ft_strpos(base, *s) != ~(!abs))
		total = total * ft_strlen(base) + ft_strpos(base, *s++);
	return (total * abs);
}

char				*ft_conv_u(char *nbr, char *base_from, char *base_to)
{
	int				i;
	unsigned int	convert;
	char			*res;

	i = 0;
	res = ft_strnew(65);
	convert = ft_atoui_base(nbr, base_from);
	while (convert > 0)
	{
		res[i++] = base_to[convert % ft_strlen(base_to)];
		convert /= ft_strlen(base_to);
	}
	res[i] = '\0';
	return (ft_strrev(res));
}

int					ft_print_uint(unsigned int nbr, t_size *len)
{
	int		y;
	char	*str;

	y = 0;
	len->count += ft_strlen(ft_uitoa(nbr));
	while (y < len->precision - ft_strlen(ft_uitoa(nbr)))
	{
		if (len->precision > 9)
			ft_putchar(' ');
		else
			ft_putchar('0');
		y++;
	}
	str = ft_uitoa(nbr);
	ft_putstr(str);
	return (0);
}
