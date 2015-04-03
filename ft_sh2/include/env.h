/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 12:55:44 by glafitte          #+#    #+#             */
/*   Updated: 2015/04/03 13:06:40 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "ft_sh2.h"

t_env	*ft_create_list(char **env);
void	ft_add_element(t_env **list, char *val, char *start);

#endif
