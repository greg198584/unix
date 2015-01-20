/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:39:40 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/20 10:41:12 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

char		*ft_ftoa(double n)
{
	int		one;
	int		state;
	char	*ptr;
	char	*ret;
	double	two;

	state = (n < 0) ? 1 : 0;
	ret = ft_itoa(n);
	ptr = ft_strdup(".");
	ret = ft_strjoin(ret, ptr);
	n *= state ? -1 : 1;
	one = (int)n;
	two = n - one;
	while (++state && (size_t)state < (sizeof(n) - 1))
		two *= 10;
	ptr = ft_itoa((int)two);
	ret = ft_strjoin(ret, ptr);
	return (ret);
}
