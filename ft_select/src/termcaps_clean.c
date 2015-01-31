/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 13:31:50 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/31 13:36:39 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_delete_char(int j, int size)
{
	char	*del_str;
	char	*str;
	int	i;

	del_str= tgetstr("dc", NULL);
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

int		ft_clear_screen(void)
{
	char	*str;

	if ((str = tgetstr("cl", NULL)) == NULL)
		return (-1);
	if (tputs(str, 0, ft_putchar) == -1)
		ft_puterror("erreur: tputs!: termcaps.c\n");
}

void		ft_clear_list(t_list *list, int pos)
{
	int		i;
	t_list	*tmp;

	tmp = list;
	i = -1;
	while (++i < pos)
		tmp = tmp->next;
	while (i <= list->size)
	{
		ft_move_cursor(i);
		ft_delete_char(i, tmp->size);
		tmp = tmp->next;
		i += 1;
	}
}
