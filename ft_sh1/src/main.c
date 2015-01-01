/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 14:11:08 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/01 16:49:45 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_clean(t_env *env)
{
	ft_free_list(env);
	exit(EXIT_SUCCESS);
}

int		main(int argc, char **argv, char **env)
{
	char	buff[BUFF + 1];
	t_env	*list;
	int		len;
	int		ret;
	(void)argc;
	(void)argv;

	list = ft_create_list(env);
	ft_init_env(list);
	ft_prompt(list, 1);
	ft_init(&buff[0]);
	ret = ft_signal();
	while ((len = read(0, buff, BUFF)) > 0)
	{
		if (len == BUFF)
			ft_puterror("erreur: commande trop grande !\n");
		buff[len != 0 ? len - 1 : len] = '\0';
		ret = ft_check(buff, list);
		if (ret == 3)
			ft_clean(list);
		ft_prompt(list, ret);
		(void)ft_signal();
		ft_init(&buff[0]);
	}
	return (len == -1 ? EXIT_FAILURE : EXIT_SUCCESS);
}
