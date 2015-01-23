/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 11:00:58 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/19 15:15:25 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_option_hexa(unsigned int nbr, char option, t_size *len)
{
	char	*nbr_x;
	char	*str;
	int		i;

	i = 0;
	nbr_x = ft_memalloc(sizeof(char) * 1024);
	str = ft_memalloc(sizeof(char) * 1024);
	if (nbr == 0)
		return ("0");
	if (nbr > 2147483647)
		nbr_x = ft_conv_u(ft_uitoa(nbr), ft_get_base(10), ft_get_base(16));
	else
		nbr_x = ft_conv_base(ft_uitoa(nbr), ft_get_base(10), ft_get_base(16));
	if (option == 'x')
		while (nbr_x[i] != '\0')
		{
			str[i] = ft_tolower(nbr_x[i]);
			i++;
		}
	else
		str = nbr_x;
	ft_print_precision(len, ft_strlen(str));
	len->count += ft_strlen(str);
	return (str);
}

char	*ft_option_octal(int nbr, char option, t_size *len)
{
	char	*nbr_o;

	nbr_o = ft_memalloc(sizeof(char) * 1024);
	if (nbr == 0)
		return ("0");
	if (option == 'o')
	{
		nbr_o = ft_conv_u(ft_uitoa(nbr), ft_get_base(10), ft_get_base(8));
		ft_print_precision(len, ft_strlen(nbr_o));
		len->count += ft_strlen(nbr_o);
		return (nbr_o);
	}
	else if (option == 'O')
	{
		nbr_o = ft_conv_base(ft_uitoa((unsigned long int)nbr), ft_get_base(10),
								ft_get_base(8));
		ft_print_precision(len, ft_strlen(nbr_o));
		len->count += ft_strlen(nbr_o);
		return (nbr_o);
	}
	else
		return (NULL);
}
