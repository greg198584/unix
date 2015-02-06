/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 21:25:31 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/06 12:59:49 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_move_cursor(int j)
{
	char	*cur;
	char	*str;

	cur = tgetstr("cm", NULL);
	if ((str = tgoto(cur, 0, j)) == NULL)
		ft_puterror("Erreur probleme avec tgoto!");
	if (tputs(str, 1, ft_putchar) == -1)
		ft_puterror("Erreur: probleme avec tputs!");
}

void	ft_visible_cursor(void)
{
	char	*cur;
	char	*str;

	cur = tgetstr("ve", NULL);
	if ((str = tgoto(cur, 0, 0)) == NULL)
		ft_puterror("Erreur probleme avec tgoto!");
	if (tputs(str, 1, ft_putchar) == -1)
		ft_puterror("Erreur: probleme avec tputs!");
}

void	ft_hide_cursor(void)
{
	char	*cur;
	char	*str;

	cur = tgetstr("vi", NULL);
	if ((str = tgoto(cur, 0, 0)) == NULL)
		ft_puterror("Erreur probleme avec tgoto!");
	if (tputs(str, 1, ft_putchar) == -1)
		ft_puterror("Erreur: probleme avec tputs!");
}
