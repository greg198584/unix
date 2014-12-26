/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 17:52:14 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/26 18:31:21 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <signal.h>

static void	ft_print(int t)
{
	(void)t;
	ft_putendl("\n$>");
}

void	ft_init(char *str)
{
	int	i;

	i = -1;
	while (++i <= BUFF)
		str[i] = '\0';
}

void	ft_prompt(t_list *env, char change)
{
	char	*pwd;
	char	*user;

	user = ft_set_var(env, "USER");
	if (change)
		pwd = ft_set_pwd(env);
	else
		pwd = ft_set_var(env, "PWD");
	if (user != NULL)
	{
		ft_putstr(user);
		ft_putstr("@");
	}
	ft_putendl(pwd);
	ft_putstr("$>");
}

char	ft_signal()
{
	if (signal(SIGINT, ft_print) == SIG_ERR)
		ft_error("error with signal in main.c: l74\n");
	return (0);
}
