/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 10:20:51 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/02 17:42:21 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
