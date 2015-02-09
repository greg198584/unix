/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 20:31:06 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/09 14:28:54 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_clear_term(t_param *p)
{
	if (tcsetattr(0, TCSANOW, p->save_term) == -1)
		return (-1);
	return (0);
}

int		ft_clear_area(void)
{
	char	*res;

	if ((res = tgetstr("cl", NULL)) == NULL)
		return (-1);
	tputs(res, 0, ft_putchar);
	return (0);
}

void	ft_delete_char(int j, int size)
{
	char	*del_str;
	char	*str;
	int		i;

	del_str = tgetstr("dc", NULL);
	i = 0;
	while (i < size)
	{
		if ((str = tgoto(del_str, i, j)) == NULL)
			ft_puterror("erreur: probleme avec tgoto!\n");
		if (tputs(str, 1, ft_putchar) == -1)
			ft_puterror("erreur: probleme avec tputs!\n");
		i += 1;
	}
}
