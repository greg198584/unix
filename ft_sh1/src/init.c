/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:49:28 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/27 16:49:04 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

void	ft_init(char *str)
{
	int		i;

	i = -1;
	while (++i <= BUFF)
		str[i] = '\0';
}

void	ft_prompt(t_env *env, char change)
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
		ft_write(user, CYAN);
		ft_write("@", BLUE);
	}
	ft_write(pwd, GREEN);
	(void)write(0, "\n", 1);
	ft_write("$>", RED);
}

static void	ft_print(int t)
{
	(void)t;
	ft_write("\n$>", RED);
}

char		ft_signal()
{
	if (signal(SIGINT, ft_print) == SIG_ERR)
		ft_puterror("error with signal in main.c: l74\n");
	return (0);
}

void		ft_write(const char *str, const char *color)
{
  (void)write(0, color, ft_strlen(color));
  (void)write(0, str, ft_strlen(str));
  (void)write(0, "\033[0m", ft_strlen("\033[0m"));
}
