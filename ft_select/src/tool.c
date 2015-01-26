/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 10:20:51 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/26 12:49:03 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char	ft_cmp_elem(const char *s1, const char *s2, char equal)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (equal)
		return (s1[i] == '=' && s2[i] == '\0');
	return ((s1[i] == s2[i] || s1[i] == ' ' || s1[i] == '\t') && s2[i] == '\0');
}

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
