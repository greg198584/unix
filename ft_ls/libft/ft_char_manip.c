/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_manip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 14:44:10 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/29 16:16:33 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_char_rep(char *str, char c1, char c2, int recurs)
{
	return (ft_strrep(str, ft_char_to_str(c1), ft_char_to_str(c2), recurs));
}

char	*ft_str_rem(char *str, char *s, int recurs)
{
	return (ft_strrep(str, s, REPLACE_EMPTY, recurs));
}

char	*ft_char_rem(char *str, char c, int recurs)
{
	return (ft_strrep(str, ft_char_to_str(c), REPLACE_EMPTY, recurs));
}

char	*ft_strtrim_right(char *s, int n)
{
	if (!s || !n || !*s)
		return (s);
	return ((n >= ft_strlen(s)) ? "" : ft_strndup(s, ft_strlen(s) - n));
}

char	*ft_strtrim_left(char *s, int n)
{
	if (!s || !n || !*s)
		return (s);
	return ((n >= ft_strlen(s)) ? "" : ft_strdup(s + (int)n));
}
