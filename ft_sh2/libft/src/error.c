/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 09:43:56 by glafitte          #+#    #+#             */
/*   Updated: 2015/04/02 11:08:44 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_puterror(char *error)
{
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	ft_err_loc(char *file, int line, char *msg)
{
	ft_fprintf(2, "Erreur: %s\n", msg);
	ft_fprintf(2, "%s", file);
	ft_fprintf(2, " at line: ");
	ft_fprintf(2, "%d\n", line);
}
