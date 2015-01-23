/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 14:11:08 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/23 23:00:56 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int		main(int argc, char **argv, char **env)
{
	char	*line;
	t_env	*list;
	int		len;
	int		ret;

	(void)argc;
	(void)argv;
	list = ft_create_list(env);
	ft_init_env(list);
	ft_prompt(list, 1);
	ret = ft_signal();
	while (1)
	{
		if ((len = get_next_line(0, &line)) > 0)
		{
			ret = ft_check(line, list);
			if (ret == 42)
				return (EXIT_SUCCESS);
			ft_prompt(list, ret);
			(void)ft_signal();
		}
	}
	return (len == -1 ? EXIT_FAILURE : EXIT_SUCCESS);
}
