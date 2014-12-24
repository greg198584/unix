/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 16:09:14 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/24 16:46:33 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include <stdlib.h>

int	ft_cd(void)
{
	ft_putendl("fonction cd");
	return (0);
}

int	ft_setenv(void)
{
	return (0);
}

int	ft_unsetenv(void)
{
	return (0);
}

int	ft_env(void)
{
	return (0);
}

int	ft_exit(void)
{
	ft_putendl("sorti du programme");
	exit(EXIT_SUCCESS);
	return (0);
}
