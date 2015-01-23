/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:18:07 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/23 09:15:00 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	ft_check(t_pos *pos)
{
	char	buffer[3];
	char	*res;

	(void)pos;
	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 4)
		{
			ft_printf("Ctrl+d: fermture du programme");
			return (0);
		}
		if (buffer[0] == 32)
			ft_putendl("Touche taper: ESP");
		if (buffer[0] == 'l')
		{
			if ((res = tgetstr("cl", NULL)) == NULL)
				return (-1);
			tputs(res, 0, ft_putchar);
		}
		else if (buffer[0] == 27 && buffer[1] == '['/* && (buffer[2] == 'A' || buffer[2] == 'B')*/)
		{
			ft_move_cursor(pos->y);
			if (buffer[2] == 'A')
				pos->y =  pos->y == 0 ? 50 : pos->y - 1;
			else if (buffer[2] == 'B')
				pos->y = pos->y < 50 ? pos->y + 1 : 0;
			ft_move_cursor(pos->y);
		}
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	char			*name_term;
	t_list			*list;
	struct termios	term;
	t_pos			pos;

	(void)env;
	ft_init_pos(pos);
	if(argc < 2)
		ft_puterror("Vous n'avez entrer aucun argument");
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	list = ft_create_list(argc, argv);
	if ((ft_init_select(name_term, &term)) == -1)
		ft_puterror("Erreur: init_select");
	ft_display_list(list);
	ft_move_cursor(0);
	ft_check(&pos);
	if((ft_clear_term(&term)) == -1)
		ft_puterror("Erreur: lors du retablissement du terminal");
	return (0);
}
