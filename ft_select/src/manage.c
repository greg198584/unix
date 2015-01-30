/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 11:46:40 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/30 10:13:02 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_manage_line(char *s, int pos, char valid, int type)
{
	int	i;

	i = -1;
	ft_move_cursor(pos);
	ft_delete(pos, ft_strlen(s));
	if (type)
		ft_start_underline(pos);
	if (valid == 1)
		ft_start_reverse(pos);
	while (++i < ft_strlen(s))
		ft_putchar(s[i]);
	ft_end_underline();
}
