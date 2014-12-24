/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ls.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 10:50:24 by glafitte          #+#    #+#             */
/*   Updated: 2014/11/27 10:27:53 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_LS_H
# define SORT_LS_H

# include "libft/libft.h"

# define F_ASCII(a, b)	(ft_strcmp(a->path, b->path) < 0)
# define F_RASCII(a, b)	(ft_strcmp(a->path, b->path) > 0)
# define F_TIME(a, b)	(ft_strcmp(ft_itoa(a), ft_itoa(b)) > 0)
# define F_RTIME(a, b)	(ft_strcmp(ft_itoa(a), ft_itoa(b)) < 0)

#endif
