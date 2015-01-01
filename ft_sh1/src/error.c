/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:40:58 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/31 16:34:08 by glafitte         ###   ########.fr       */
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

void	ft_error(const char *error, const char *var)
{
	ft_putstr_fd(var, 2);
	ft_putstr_fd(":", 2);
	ft_putstr_fd(error, 2);
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

char	ft_conf(char *cmd)
{
	ft_printf("Si %s", cmd);
	ft_putstr_fd("' n'est pas une faute de frappe utiliser la commande ", 2);
	ft_putstr_fd(" not found pour voir ce qu'il contient:\n\tconf ", 2);
	ft_putendl_fd(cmd, 2);
	return (-1);
}
