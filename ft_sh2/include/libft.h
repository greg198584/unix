/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/04 08:16:28 by glafitte          #+#    #+#             */
/*   Updated: 2015/04/01 15:24:10 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define REPLACE_ONCE	0
# define REPLACE_EMPTY	""
# define BUFF_SIZE		0x2323

typedef struct			s_gnlp
{
	int					fd;
	char				*buf;
	struct s_gnlp		*next;
}						t_gnlp;

int						ft_gnl(int const fd, char **line);
void					ft_freetab(char ***tab);
int						ft_fprintf(int fd, char const *format, ...);
int						ft_strlen_s(const char *str);
void					ft_puterror(char *error);
int						ft_abs(int a);
void					ft_putstr(char const *s);
void					ft_putchar(char c);
int						ft_strcmp(char const *s1, char const *s2);
int						ft_strlen(const char *str);
void					ft_putnbr(int n);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
									size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strcat(char *dst, const char *src);
char					*ft_strncat(char *dst, const char *src, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_isalpha(int c);
int						ft_isupper(int c);
int						ft_islower(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_tolower(int c);
int						ft_toupper(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strsub(char const *s,
									unsigned int start, size_t len);
char					*ft_strtrim(char const *s);
int						ft_isspace(int c);
char					*ft_itoa(int n);
char					*ft_strdup(char *src);
int						ft_atoi(char *str);
char					**ft_strsplit(char const *s, char c);
void					ft_putendl(char const *s);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
int						ft_pow(int n, int p);
int						ft_match(char const *s1, char const *s2);
char					*ft_strndup(char const *src, size_t len);
int						ft_active_bits(int n);
char					*ft_strrev(char *s);
char					*ft_char_to_str(char c);
char					*ft_char_rep(char *str, char c1, char c2, int recurs);
char					*ft_str_rem(char *str, char *s, int recurs);
char					*ft_char_rem(char *str, char c, int recurs);

#endif
