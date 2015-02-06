/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 15:31:16 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/06 15:35:53 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_recup_signal(int signal)
{
	(void)signal;
}

int			ft_signal(void)
{
	if (signal(SIGTSTP, ft_recup_signal) == SIG_ERR)
		ft_puterror("Erreur: signal");
	return (0);
}
