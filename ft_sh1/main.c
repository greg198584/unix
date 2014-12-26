/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 14:29:23 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/26 19:04:16 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv, char **env)
{
	t_list	*list;
	char	buff[BUFF + 1];
	int		len;
	int		result;

	(void)argc;
	(void)argv;
	list = ft_create_list(env);
	ft_init_env(list);
	ft_prompt(list, 1);
	ft_init(&buff[0]);
	result = ft_signal();
	while ((len = read(0, buff, BUFF)) > 0)
	{
		if (len == BUFF)
			ft_error("error: command trop grande !");
		buff[len != 0 ? len - 1 : len] = '\0';
		result = ft_checking_arg(buff, list);
		ft_prompt(list, result);
		(void)ft_signal();
		ft_init(&buff[0]);
	}
	return (len == -1 ? EXIT_FAILURE : EXIT_SUCCESS);
}
