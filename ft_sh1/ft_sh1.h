/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 14:30:12 by glafitte          #+#    #+#             */
/*   Updated: 2014/12/24 16:50:09 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include "libft/libft.h"

int	ft_checking_arg(char *arg);
int	ft_exit(void);
int	ft_cd(void);
int	ft_setenv(void);
int	ft_unsetenv(void);
int	ft_env(void);
int	ft_exec(char *prg);

#endif