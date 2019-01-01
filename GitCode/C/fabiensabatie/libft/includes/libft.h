/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:49:41 by fsabatie          #+#    #+#             */
/*   Updated: 2018/02/04 13:18:51 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <wchar.h>
# include <stdarg.h>
# include <inttypes.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# define BUFF_SIZE 100000
# define BEFORE 0
# define AFTER 1
# define DIGITS 0
# define POST 1
# define CHAR 0
# define STR 1
# define WCHAR 2
# define WSTR 3
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define PURPLE		"\x1b[36m"
# define CR			"\x1b[39m"
# define BLINKON	"\x1b[5m"
# define BLINKOFF	"\x1b[25m"
# define P_ALLOC(x, y, z) if(!(x = (y)ft_memalloc(z))) exit(1);
# define IFRET(x, y) if(x) return (y)
# define IF(x, y) if(x) (y)
# define POW2(x) (x) * (x)

/*
** PRINTF
*/

typedef enum	e_bool
{
	TRUE,
	FALSE
}				t_bool;

typedef enum	e_mod
{
	H,
	HH,
	L,
	LL,
	J,
	Z,
	X
}				t_mod;

typedef struct		s_print
{
	va_list			ap;
	char			*format;
	char			*buffer;
	char			*digits;
	char			flag;
	t_mod			mod;
	int				ptr;
	int				wchar;
	char			*hash;
	int				h;
	char			*color;
	int				blink;
	int				mfw;
	int				ip;
	int				prec;
	int				oprec;
	int				pad_is;
	char			pad_char;
	char			sign;
	int				base;
	int				nb_ispos;
	int				nb_digits;
	intmax_t		arg;
	size_t			cnt;
	int				zeros;
}					t_print;

int					ft_printf(const char *format, ...);
int					ft_sprintf(char **str, const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
void				ft_vprintf(t_print *s);
void				handle_post_digit(t_print *s, int mode, int i);
void				fill_buffer(t_print *s, int mode, char *str, char c);
void				wchar_tobuffer(t_print *s, wchar_t c);
void				handle_signs(t_print *s);
void				pad(t_print *s);
void				process_flag(t_print *s);
void				handle_nb(t_print *s);
void				handle_str(t_print *s);
void				handle_zero(t_print *s);
void				handle_special(t_print *s);
void				handle_bonus(t_print *s);

/*
** GET_NEXT_LINE
*/

typedef struct		s_file
{
	char			*memstr;
	char			*start;
	int				fd;
	struct s_file	*next;
}					t_file;


int					get_next_line(const int fd, char **line);

/*
** LIBFT
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_vec
{
	float			x;
	float			y;
}					t_vec;

typedef struct		s_equa
{
	float			x;
	float			y;
	float			a;
	float			b;
}					t_equa;

unsigned long long	ft_abs(int n);
size_t				ft_strlen(char *str);
size_t				ft_wstrlen(wchar_t *wstr);
size_t				ft_strcount(char *haystack, char needle);
size_t				ft_strlcat(char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_atoi(char *str);
int					ft_strcmp(char *s1, char *s2);
int					ft_memcmp(void *s1, void *s2, size_t n);
int					ft_strcpos(char *haystack, char needle);
int					ft_strrpos(char *haystack, char needle);
int					ft_strncmp(char *s1, char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_putnbr(int nb);
void				ft_strclr(char *s);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putstr(char *str);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_putwchar(wchar_t c);
void				ft_putwstr(wchar_t *str);
void				ft_putendl(char const *s);
void				*ft_memalloc(size_t size);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_swapvec(t_vec *a, t_vec *b);
void				*ft_bzero(void *str, size_t len);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				*ft_memchr(void *s, int c, size_t n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_striter(char *s, void (*f)(char *));
void				*ft_memset(void *str, int c, size_t len);
void				*ft_memcpy(void *dst, void *src, size_t n);
void				*ft_memmove(void *dst, void *src, size_t n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				*ft_memccpy(void *dst, void *src, int c, size_t n);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_itoa(int n);
char				*ft_strrev(char *str);
char				*ft_strdup(char *src);
char				*ft_chartostr(char c);
char				*ft_strnew(size_t size);
char				*ft_strtrim(char const *s);
char				*ft_strchr(char *str, int c);
char				*ft_strrchr(char *str, int c);
char				*ft_strcat(char *s1, char *s2);
char				*ft_strcpy(char *dst, char *src);
char				*ft_strnsub(char const *s, int n);
char				ft_chrstr(char *hay, char *needle);
char				*ft_strcsub(char const *s, char c);
char				**ft_strsplit(char const *s, char c);
char				*ft_retsplit(char *str, char c, int n);
char				*ft_strstr(char *haystack, char *needle);
char				*ft_strjoin_char(char const *s1, char c);
char				*ft_strncat(char *s1, char *s2, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				ft_chrcstr(char *hay, char *needle, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strncpy(char *dst, char *src, size_t n);
char				*ft_strjoinfree(char const *s1, char const *s2);
char				*ft_strnstr(char *haystack, char *needle, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
wchar_t				*ft_wstrnsub(wchar_t *s, int n);
t_vec				*ft_vecnew(float x, float y);
t_vec				*ft_getmidcoor(t_vec *a, t_vec *b);
t_vec				*ft_get_perpendicular_vec(t_vec *a, t_bool way);
t_equa				*ft_equanew(float x, float y, float a, float b);

#endif
