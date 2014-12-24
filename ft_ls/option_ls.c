/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 16:37:14 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/26 10:44:16 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_ls.h"
#include <stdlib.h>

static void	ft_usage_error(char c)
{
	char	*s;

	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	s = ft_strrep("\nusage: ft_ls [-%s] [file ...]", "%s", OPT_LIST, ONE);
	ft_putendl(s);
	exit(EXIT_FAILURE);
}

static int	ft_get_options(char c, int opt, char *option_list)
{
	unsigned int	i;

	i = -1;
	while (++i < ft_strlen(option_list))
	{
		if (c == option_list[i])
			return (!(opt & ft_pow(2, i)) ? (opt |= ft_pow(2, i)) : opt);
	}
	ft_usage_error(c);
	return (1);
}

int			ft_init_options(char **argv, int *start)
{
	int	opt;
	int	i;
	int j;

	i = 0;
	opt = 0;
	while (argv[++i] != '\0')
	{
		if ((j = 1) && argv[i][0] == '-')
		{
			while (argv[i][j] != '\0' && opt >= 0)
				opt = ft_get_options(argv[i][j++], opt, OPT_LIST);
		}
		else
			break ;
	}
	*start = i;
	return (opt);
}
