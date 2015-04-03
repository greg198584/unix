/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 15:46:05 by glafitte          #+#    #+#             */
/*   Updated: 2015/04/03 14:01:44 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh2.h"
#include <stdlib.h>

static	int	ft_shell(t_env *list)
{
	(void)list;
	char	*line;
	int		ret;

	while (1)
	{
		if ((ret = ft_gnl(0, &line)) > 0)
			ft_fprintf(1, "%s\n", line);
		free(line);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;

	ft_shell(NULL);
	return (0);
}
