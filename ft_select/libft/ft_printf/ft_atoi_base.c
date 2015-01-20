/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 08:38:28 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/19 11:13:25 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_atoi_base(char *s, char *base)
{
	int	abs;
	int	total;

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
