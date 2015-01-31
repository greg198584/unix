/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 12:03:01 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/31 14:05:50 by glafitte         ###   ########.fr       */
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

# define START_UNDERLINE	"us"
# define END_UNDERLINE		"me"
# define START_REVERSE		"mr"
# define CLEAR_SCREEN		"cl"
# define DELETE_CHAR		"dc"

typedef struct termios		t_termios;

typedef struct				s_list
{
	char					*data;
	struct s_list			*next;
	struct s_list			*prev;
	char					valid;
	int						size;
}							t_list;

typedef struct				s_pos
{
	int						x;
	int						y;
	int						fd;
}							t_pos;

typedef struct				s_param
{
	char					buffer[4];
	t_pos					pos;
	int						value;
	int						width;
	int						height;
	int						count;
}							t_param;

typedef struct				s_keyboard
{
	int						(*func_ptr)(t_param *p, t_list *list, t_termios *term);
	int						key;
}							t_keyboard;

void						ft_visible_cursor(void);
int							ft_display_list(t_list *list);
int							ft_init_select(char *name_term, t_termios *term);
int							ft_init_pos(t_param *p, int argc);
void						ft_move_cursor(int j);
int							ft_clear_area(void);
int							ft_move(t_param *p, t_list *list, t_termios *term);
int							ft_space(t_param *p, t_list *list, t_termios *term);
int							ft_exit(t_param *p, t_list *list, t_termios *term);
void						ft_remove_element(t_list *lst, char *value);
t_list						*ft_create_list(int argc, char **argv);
t_list						*ft_ret_elt(t_list *lst, int pos);
void						ft_hide_cursor(void);
int							ft_check(t_param *p, t_list *list, t_termios *term);
void						ft_init_value(t_param *p, t_list *list);
void						ft_init_down(t_param *p, t_list *list);
void						ft_init_up(t_param *p, t_list *list);
void						ft_delete(int pos, int size);
char						ft_signal(t_param *p);
int							ft_del(t_param *p, t_list *list, t_termios *term);
void						ft_list_remove(t_list *list, int pos);
void						ft_clear_list(t_list *list, int pos);
void						ft_line(char *s, int pos, char valid, int type);
int							ft_clear_term(t_termios *term);
void						ft_end_underline();
void						ft_start_reverse(int y);
void						ft_start_underline(int y);
void						ft_delete_char(int j, int size);

#endif
