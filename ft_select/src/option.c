/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 17:59:40 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/25 21:33:24 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_exit(t_param *p, t_list *list, t_termios *term)
{
	(void)p;
	(void)list;

	ft_putendl("fermeture du programme");
	if((ft_clear_term(term)) == -1)
		ft_puterror("Erreur: lors du retablissement du terminal");
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_space(t_param *p, t_list *list, t_termios *term)
{
	(void)p;
	(void)list;
	(void)term;

	ft_putendl("Touche taper: ESP");
	return (0);
}

void	ft_delete(int j, int size)
{
	char	*del_char;
	char	*str;
	int	i;

	del_char = tgetstr("dc", NULL);
	i = 0;
	while (i < size)
	{
		if ((str = tgoto(del_char, i, j)) == NULL)
			ft_puterror("erreur: problem tgoto: option.c!\n");
		if (tputs(str, 1, ft_putchar) == -1)
			ft_puterror("erreur: problem tputs: option.c!\n");
		i += 1;
	}
}

int	ft_check_mov(t_param *p, t_list *list, t_termios *term)
{
	if (p->buffer[0] == 27 && p->buffer[1] == '[')
	{
		ft_move_cursor(p->pos.y);
		if (!p->value)
			ft_init_value(p, list);
		if (p->buffer[2] == 'A')
			ft_init_down(p, list);
		else if (p->buffer[2] == 'B')
			ft_init_up(p, list);
		ft_manage_line(ft_ret_elt(list, p->pos.y)->data, p->pos.y, 1);
	}
	else
		ft_exit(p, list, term);
	return (0);
}
