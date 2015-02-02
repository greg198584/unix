/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 12:26:20 by glafitte          #+#    #+#             */
/*   Updated: 2015/01/20 11:28:53 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>
# include <stdarg.h>
# include <stdlib.h>

# define INT_D		'd'
# define INT_I		'i'
# define STRING_1	's'
# define STRING_2	'S'
# define CHARAC_1	'c'
# define CHARAC_2	'C'
# define ADRESS		'p'
# define UINT_D		'D'
# define UINT_U		'u'
# define HEXA_1		'x'
# define HEXA_2		'X'
# define OCTAL_1	'o'
# define OCTAL_2	'O'
# define FLOAT		'f'

typedef struct		s_size
{
	int				count;
	int				precision;
	int				nbr;
	char			*pl;
}					t_size;

int					ft_printf(const char *format, ...);
int					ft_atoi_base(char *s, char *base);
int					ft_strpos(char const *str, char c);
char				*ft_conv_base(char *nbr, char *base_from, char *base_to);
char				*ft_get_base(int n);
void				ft_uint_convers(void);
void				ft_float_convers(void);
int					ft_detect_fmt(va_list ap, char option);
char				*ft_uitoa(unsigned long int nbr);
char				*ft_option_hexa(unsigned int nbr, char option, t_size *len);
char				*ft_conv_u(char *nbr, char *base_from, char *base_to);
int					ft_checking_c(char c, char option, t_size *len);
int					ft_test_big_c(char c);
int					ft_test_big_s(const char *fmt, int i, va_list ap);
int					ft_check_string(char *str, char option, t_size *size);
int					ft_precision_nbr(int i, t_size *len);
int					ft_precision_checking(const char *format, int *i,
											t_size *len);
int					ft_print_uint(unsigned int nbr, t_size *len);
int					ft_putstr_and_precision(char *str, t_size *len);
int					ft_print_precision(t_size *len, int size);
char				*ft_option_octal(int nbr, char option, t_size *len);
unsigned int		ft_putnbr_hexa(char *str, unsigned int nb, char option,
									t_size *len);
unsigned int		ft_atoui(char *str, unsigned int i);
char				*ft_ftoa(double n);
float				ft_atof(const char *str);

#endif
