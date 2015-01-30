/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 11:31:50 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/30 16:59:29 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_end_underline()
{
	char	*str;
	char	*es;

	es = tgetstr("me", NULL);
	if ((str = tgoto(es, 0, 0)) == NULL)
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

int		ft_clear_screen(void)
{
	char	*str;

	if ((str = tgetstr("cl", NULL)) == NULL)
		return (-1);
	if (tputs(str, 0, ft_putchar) == -1)
		ft_puterror("erreur: tputs!: termcaps.c\n");
}
