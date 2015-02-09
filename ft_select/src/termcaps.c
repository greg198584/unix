/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 11:31:50 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/09 14:33:43 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_end_underline(void)
{
	char	*str;
	char	*me;

	me = tgetstr("me", NULL);
	if ((str = tgoto(me, 0, 0)) == NULL)
		ft_puterror("erreur: tgoto! : termcaps.c\n");
	if (tputs(str, 1, ft_putchar) == -1)
		ft_puterror("erreur: tputs!: termcaps.c\n");
}

void	ft_start_underline(int y)
{
	char	*us;
	char	*str;

	us = tgetstr("us", NULL);
	if ((str = tgoto(us, 0, y)) == NULL)
		ft_puterror("erreur: tgoto! : termcaps.c\n");
	if (tputs(str, 1, ft_putchar) == -1)
		ft_puterror("erreur: tputs!: termcaps.c\n");
}

void	ft_start_reverse(int y)
{
	char	*us;
	char	*str;

	us = tgetstr("mr", NULL);
	if ((str = tgoto(us, 0, y)) == NULL)
		ft_puterror("erreur: tgoto! : termcaps.c\n");
	if (tputs(str, 1, ft_putchar) == -1)
		ft_puterror("erreur: tputs!: termcaps.c\n");
}
