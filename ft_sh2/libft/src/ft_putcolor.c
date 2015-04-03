/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 13:53:18 by glafitte          #+#    #+#             */
/*   Updated: 2015/04/03 14:01:21 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putcolor(const char *str, const char *color, int i)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr("\033[0m");
	if (i == 1)
		ft_putchar('\n');
}
