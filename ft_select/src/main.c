/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:18:07 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/23 22:44:34 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_keyboard ft_touch[]=
{
	{&ft_exit, 4},
	{&ft_exit, 3},
	{&ft_space, 32},
	{&ft_check_move, 27},
	{NULL, -1}
};

static int	ft_check(t_pos *pos, t_list *list, t_termios *term)
{
	int		res;
	int 	i;

	i = -1;
	while (1)
	{
		read(0, pos->buffer, 3);
		while (ft_touch[++i].key != -1)
		{
			if (i == 5)
				i = 0;
			if (ft_touch[i].key == pos->buffer[0])
				res = (ft_touch[i].func_ptr(pos, list, term));
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
	ft_clear_area();
	ft_display_list(list);
	ft_move_cursor(0);
	ft_check(&pos, list, &term);
	return (0);
}
