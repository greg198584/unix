/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:19:50 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/22 20:34:36 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_init_select(char *name_term, t_termios *term)
{
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

int		ft_init_pos(t_pos pos)
{
	if ((pos.fd = open("/dev/tty", O_WRONLY, O_NOCTTY)) == -1)
		ft_puterror("erreur: lors de l'ouverture du fichier!\n");
	pos.x = 0;
	pos.y = 0;
	return (0);
}
