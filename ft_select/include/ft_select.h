/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 12:03:01 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/23 08:19:50 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <term.h>
# include <curses.h>
# include <errno.h>
# include <fcntl.h>

typedef struct termios t_termios;

typedef struct		s_list
{
	char			*data;
	struct s_list	*next;
}					t_list;

typedef struct		s_pos
{
	int				x;
	int				y;
	int				fd;
}					t_pos;

void				ft_visible_cursor();
int					ft_display_list(t_list *list);
t_list				*ft_create_list(int argc, char **argv);
int					ft_init_select(char *name_term, t_termios *term);
int					ft_init_pos(t_pos pos);
int					ft_clear_term(t_termios *term);
void				ft_move_cursor(int j);

#endif
