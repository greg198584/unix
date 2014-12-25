/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 16:04:34 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/25 16:09:13 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <stdlib.h>

int	ft_call_option(char *arg)
{
	if (!ft_strcmp(arg, "exit"))
	{
		ft_putendl("sorti du programme");
		exit(EXIT_SUCCESS);
		return (1);
	}
	else if(!ft_strcmp(arg, "cd"))
		return (ft_cd());	
	else if (!ft_strcmp(arg, "pwd"))
		return (ft_pwd());
	return (0);
}

int	ft_checking_arg(char *arg)
{
	if (ft_call_option(arg) != 0)
		return (0);
	else
		ft_exec(arg);
	return (0);
}
