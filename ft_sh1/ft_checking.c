/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 16:04:34 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/24 16:52:47 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int	ft_checking_arg(char *arg)
{
	if (!ft_strcmp(arg, "exit"))
		ft_exit();
	else if(!ft_strcmp(arg, "cd"))
		ft_cd();
	else
		ft_exec(arg);
	return (0);
}
