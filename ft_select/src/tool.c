/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 10:20:51 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/30 17:31:59 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_delete(int pos, int size)
{
	char	*del_char;
	char	*str;
	int	i;

	del_char = tgetstr("dc", NULL);
	i = 0;
	while (i < size)
	{
		if ((str = tgoto(del_char, i, pos)) == NULL)
			ft_puterror("erreur: problem tgoto: option.c!\n");
		if (tputs(str, 1, ft_putchar) == -1)
			ft_puterror("erreur: problem tputs: option.c!\n");
		i += 1;
	}
}

static void	ft_recup_signal(int signal)
{
	(void)signal;
	return ;
}

char	ft_signal(t_param *p)
{
	if (signal(SIGWINCH, ft_recup_signal))
	{
		p->width = tgetnum("co");
		p->height = tgetnum("li");
	}
	//ft_printf("valeur de width  = [ %d ]\n", p->width);
	//ft_printf("valeur de height = [ %d ]\n", p->height);
	return (0);
}
