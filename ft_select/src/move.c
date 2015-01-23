/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 20:10:37 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/23 08:19:56 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_move_cursor(int j)
{
	char	*cur;
	char	*str;

	cur = tgetstr("cm", NULL);
	if ((str = tgoto(cur, 0, j)) == NULL)
		ft_puterror("error: problem with tgoto!");
	if (tputs(str, 1, ft_putchar) == -1)
		ft_puterror("error: problem with tputs!");
}

void	ft_visible_cursor()
{
	char	*cur;
	char	*str;

	cur = tgetstr("ve", NULL);
	if ((str = tgoto(cur, 0, 0)) == NULL)
		ft_puterror("error: problem with tgoto!\n");
	if (tputs(str, 1, ft_putchar) == -1)
		ft_puterror("error: problem with tputs!\n");
}
