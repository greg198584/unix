/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 17:59:40 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/23 22:22:53 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_exit(t_pos *pos, t_list *list, t_termios *term)
{
	(void)pos;
	(void)list;

	ft_putendl("fermeture du programme");
	if((ft_clear_term(term)) == -1)
		ft_puterror("Erreur: lors du retablissement du terminal");
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_space(t_pos *pos, t_list *list, t_termios *term)
{
	(void)pos;
	(void)list;
	(void)term;

	ft_putendl("Touche taper: ESP");
	return (0);
}

int	ft_check_move(t_pos *pos, t_list *list, t_termios *term)
{
	(void)term;
	if (pos->buffer[0] == 27 && pos->buffer[1] == '[')
	{
		ft_move_cursor(pos->y);
		if (pos->buffer[2] == 'A')
			pos->y =  pos->y == 0 ? list->count : pos->y - 1;
		else if (pos->buffer[2] == 'B')
			pos->y = pos->y < list->count ? pos->y + 1 : 0;
		ft_move_cursor(pos->y);
	}
	else
		ft_puterror("Echappement");
	return (0);
}
