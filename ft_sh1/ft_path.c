/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 16:00:41 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/26 16:20:55 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh1.h>
#include <stdlib.h>

char	ft_goodpath(char *str)
{
	int		i;
	char	path_bin;

	i = -1;
	path_bin = 0;
	while (str[++i] && path_bin == 0)
		if (str[i] == '/')
			path_bin = 1;
	return(path_bin);
}

char	*ft_pathfile(char *path, char *exec)
{
	char	*result;
	int		len;
	int		size;

	len = ft_strlen(path);
	size = (path[len - 1] == '/') ? len : len + 1;
	if ((result = malloc(sizeof(char) * (size + ft_strlen(exec) + 1))) == NULL)
		ft_error("Error: probleme d'allocation memoire\n");
	result[0] = '\0';
	result = ft_strcat(result, path);
	if (len != size)
		result[len] = '/';
	result[size] = '\0';
	result = ft_strcat(result, exec);
	return (result);
}
