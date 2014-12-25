/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 14:29:23 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/25 11:53:36 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <fcntl.h>

int	main(void)
{
	int		i;
	char	*line;

	ft_putstr("$>");
	while ((i = get_next_line(0, &line) > 0))
	{
		if (!*line)
			ft_putstr("$>");
		else
		{
			ft_checking_arg(line);
			ft_putstr("$>");
		}
	}
	return (0);
}
