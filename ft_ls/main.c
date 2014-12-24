/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 16:36:55 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/27 08:39:26 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_ls.h"

int	main(int argc, char **argv)
{
	char	*argv_dir;
	int		opt;
	int		option_end;

	option_end = 0;
	if ((opt = ft_init_options(argv, &option_end)) == OPT_ERROR)
		return (0);
	argv_dir = (argv[option_end] != '\0') ? argv[option_end] : ".";
	ft_get_dir(argv_dir, opt);
	return (0);
}
