/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:19:50 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/09 14:44:08 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_init_select(t_param *p, char *name_term, t_termios *term)
{
	t_winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	p->width = w.ws_col;
	p->height = w.ws_row;
	if (p->count > p->height)
		ft_puterror("Erreur: Trop d'arguments , veuillez redimenssionner !");
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, p->save_term) == -1)
		return (-1);
	if (tcgetattr(0, term) == -1)
		return (-1);
	term->c_lflag &= ~ICANON;
	term->c_lflag &= ~ECHO;
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, term) == -1)
		ft_puterror("Erreur: initialisation du terminal --> [tcsetattr]");
	return (0);
}

int		ft_init_pos(t_param *p, int argc)
{
	if ((p->pos.fd = open("/dev/tty", O_WRONLY, O_NOCTTY)) == -1)
		ft_puterror("erreur: lors de l'ouverture du fd [ tty ]!\n");
	p->pos.y = 0;
	p->count = argc - 2;
	return (0);
}
