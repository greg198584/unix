/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 20:31:06 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/23 11:56:54 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_clear_term(t_termios *term)
{
	if (tcgetattr(0, term) == -1)
		return (-1);
	term->c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, term) == -1)
		return(-1);
	return (0);
}

int	ft_clear_area(void)
{
	char	*res;

	if ((res = tgetstr("cl", NULL)) == NULL)
		return (-1);
	tputs(res, 0, ft_putchar);
	return (0);
}
