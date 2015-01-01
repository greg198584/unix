/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:49:28 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/29 14:36:07 by glafitte         ###   ########.fr       */
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

void		ft_init(char *str)
{
	int		i;

	i = -1;
	while (++i <= BUFF)
		str[i] = '\0';
}

void		ft_prompt(t_env *env, char change)
{
	char	*pwd;
	char	*user;

	user = ft_set_var(env, "USER");
	if (change)
		pwd = ft_pwd(env);
	else
		pwd = ft_set_var(env, "PWD");
	if (user != NULL)
	{
		ft_putstr_color(user, CYAN, 0);
		ft_putstr_color(" ==> ", BLUE, 0);
	}
	ft_putstr_color(pwd, GREEN, 1);
	ft_putstr_color("$>", RED, 0);
}

char		ft_signal()
{
	if (signal(SIGINT, ft_print) == SIG_ERR)
		ft_puterror("erreur avec le signal dans init.c\n");
	return (0);
}
