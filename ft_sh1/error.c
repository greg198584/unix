/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:40:58 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/27 15:45:43 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <ft_sh1.h>

void	ft_puterror(const char *error)
{
	(void)write(2, error, ft_strlen(error));
	exit(EXIT_FAILURE);
}

void	ft_error(const char *error, const char *var)
{
	(void)write(2, var, ft_strlen(var));
	(void)write(2, ": ", 3);
	(void)write(2, error, ft_strlen(error));
}

char	ft_env_error(char *env, char type, int pos)
{
	if (type == 0)
	{
		(void)write(2, "env: invalid option --'", 23);
		(void)write(2, env, ft_strlen(env));
		(void)write(2, "'", 1);
	}
	else if (type == 1)
	{
		(void)write(2, "env: invalid option --'", 23);
		(void)write(2, &env[pos], 1);
		(void)write(2, "'", 1);
	}
	else if (type == 2)
		(void)write(2, "env: option requires an argument -- 'u'\n", 40);
	else
		(void)write(2, "env: cannot unset '': Invalid argument\n", 39);
	if (type != 3)
		(void)write(2, "\nTry 'env --help' for more information.\n", 41);
	return (-1);
}

char	ft_cnf(char *cmd)
{
	(void)write(2, "If '", 4);
	(void)write(2, cmd, ft_strlen(cmd));
	(void)write(2, "' is not a typo you can use command-not-found to lookup", 55);
	(void)write(2, " the package that contains it, like this:\n\tcnf ", 47);
	(void)write(2, cmd, ft_strlen(cmd));
	(void)write(2, "\n", 1);
	return (-1);
}
