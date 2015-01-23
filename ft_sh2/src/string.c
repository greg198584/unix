/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 12:57:34 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/23 22:56:52 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <unistd.h>

char	ft_strcmp_shell(const char *s1, const char *s2, char equal)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (equal)
		return (s1[i] == '=' && s2[i] == '\0');
	return ((s1[i] == s2[i] || s1[i] == ' ' || s1[i] == '\t') && s2[i] == '\0');
}

void	ft_putstr_color(const char *str, const char *color, int i)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr("\033[0m");
	if (i == 1)
		ft_putchar('\n');
}
