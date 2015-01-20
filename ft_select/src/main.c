/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:18:07 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/20 17:07:24 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <curses.h>
#include <errno.h>
#include <stdio.h>

int	ft_check(void)
{
	char	buffer[3];

	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 4)
		{
			ft_printf("Ctrl+d - quitte le programme");
			return (0);
		}
		ft_printf("valeur taper: [%s]\n", buffer);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	char			*name_term;
	struct termios	term;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	return (0);
}
