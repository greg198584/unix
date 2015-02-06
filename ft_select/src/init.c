/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:19:50 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/06 10:06:49 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_init_select(t_param *p, char *name_term, t_termios *term)
{
	t_winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	p->width = w.ws_row;
	p->height = w.ws_col;
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, term) == -1)
		return (-1);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (-1);
	return (0);
}

int		ft_init_pos(t_param *p, int argc)
{
	if ((p->pos.fd = open("/dev/tty", O_WRONLY, O_NOCTTY)) == -1)
		ft_puterror("erreur: lors de l'ouverture du fichier!\n");
	p->pos.y = 0;
	p->count = argc - 2;
	return (0);
}
