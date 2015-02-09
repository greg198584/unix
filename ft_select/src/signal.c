/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 15:31:16 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/09 14:18:12 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_list		*g_list;
static t_termios	*g_term;
static t_param		*g_p;
static char			*g_name_term;

static void	ft_reinit(void)
{
	int	i;

	i = -1;
	ft_init_select(g_p, g_name_term, g_term);
	ft_clear_area();
	ft_putendl("reouverture programme");
	ft_display_list(g_list);
	g_p->pos.y = 0;
	while (++i < g_p->count)
		ft_init_up(g_p, g_list);
}

static void	ft_recup_signal(int signal)
{
	(void)signal;
	ft_reinit();
}

int			ft_signal(t_param *p, t_list *lst, t_termios *term, char *name_term)
{
	g_list = lst;
	g_p = p;
	g_term = term;
	g_name_term = name_term;
	if (signal(SIGCONT, ft_recup_signal) == SIG_ERR)
		ft_puterror("Erreur: signal");
	return (0);
}
