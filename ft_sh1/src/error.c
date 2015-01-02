/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:40:58 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/02 22:23:17 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <ft_sh1.h>

void	ft_puterror(const char *error)
{
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}

int		ft_error(const char *error, const char *var)
{
	ft_putstr_fd(var, 2);
	ft_putstr_fd(":", 2);
	ft_putstr_fd(error, 2);
	return (1);
}

char	ft_env_error(char *env, char type, int pos)
{
	if (type == 0)
	{
		ft_putstr_fd("env: invalid option --'", 2);
		ft_putstr_fd(env, 2);
		ft_putstr_fd("'", 2);
	}
	else if (type == 1)
	{
		ft_putstr_fd("env: invalid option --'", 2);
		ft_putstr_fd(&env[pos], 2);
		ft_putstr_fd("'", 2);
	}
	else if (type == 2)
		ft_putstr_fd("env: option a besoin d'un d'argument -- 'u'\n", 2);
	else
		ft_putstr_fd("env: environment invalide\n", 2);
	if (type != 3)
		ft_putstr_fd("env : erreur dans son utilisation\n", 2);
	return (-1);
}

int		ft_notfound(char *cmd)
{
	ft_printf("ft_minishell: commande introuvable: %s\n", cmd);
	return (-1);
}
