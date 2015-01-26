/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 11:46:40 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/26 13:57:33 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_manage_line(char *str, int pos, int valid, int type)
{
	int	i;

	i = -1;
	ft_move_cursor(pos);
	ft_delete(pos, ft_strlen(str));
	if (type)
		ft_start_underline(pos);
	if (valid)
		ft_start_reverse(pos);
	while (++i < ft_strlen(str))
		ft_putchar(str[i]);
	ft_end_underline();
}
