/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:18:07 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/09 14:31:16 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	main(int argc, char **argv, char **env)
{
	t_list			*list;
	struct termios	term;
	t_param			param;
	char			*name_term;

	(void)env;
	ft_init_pos(&param, argc);
	param.value = 0;
	param.nb_elt = 0;
	if (argc < 2)
		ft_puterror("Vous n'avez entrer aucun argument");
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	list = ft_create_list(argc, argv);
	if ((ft_init_select(&param, name_term, &term)) == -1)
		ft_puterror("Erreur: init_select");
	ft_clear_area();
	ft_display_list(list);
	ft_move_cursor(0);
	ft_refresh_buff(&param);
	ft_signal(&param, list, &term, name_term);
	ft_check(&param, list, &term);
	return (0);
}
