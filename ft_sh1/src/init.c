/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:49:28 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/03 18:57:06 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

static void	ft_print(int t)
{
	(void)t;
	ft_putstr_color("\n$>", RED, 0);
}

void		ft_prompt(t_env *env, int change)
{
	char	*pwd;

	if (change)
		pwd = ft_set_pwd(env);
	else
		pwd = ft_set_var(env, "PWD");
	ft_putstr_color(pwd, GREEN, 1);
	ft_putstr_color("$>", RED, 0);
}

char		ft_signal(void)
{
	if (signal(SIGINT, ft_print) == SIG_ERR)
		ft_puterror("erreur avec le signal dans init.c\n");
	return (0);
}
