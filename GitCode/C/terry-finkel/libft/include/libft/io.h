/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:39:27 by nfinkel           #+#    #+#             */
/*   Updated: 2018/05/08 19:46:25 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include <stdio.h>
# include <fcntl.h>
# include "libft/vec.h"

extern int		ft_asprintf(char **ret, const char *format, ...);
extern int		ft_dprintf(int fd, const char *format, ...);
NEV				ft_fatal(const char *s, int errcode);
extern int		ft_fprintf(FILE *stream, const char *format, ...);
extern int		ft_printf(const char *format, ...);
extern void		ft_putchar(char c);
extern void		ft_putchar_fd(char c, int fd);
extern void		ft_putendl(const char *s);
extern void		ft_putendl_fd(const char *s, int fd);
extern void		ft_putm4(t_m4 matrix);
extern void		ft_putnbr(int n);
extern void		ft_putnbr_fd(int n, int fd);
extern void		ft_putstr(const char *s);
extern void		ft_putstr_fd(const char *s, int fd);
extern void		ft_putv3(t_v3 vec);
extern void		ft_putv4(t_v4 vec);
extern ssize_t	ft_read(int filedes, void *buf, size_t nbyte);
extern char		*ft_readfile(const char *path);
extern int		ft_snprintf(char *str, size_t size, const char *format, ...);
extern int		ft_sprintf(char *str, const char *format, ...);
extern int		ft_vasprintf(char **ret, const char *format, va_list ap);
extern int		ft_vdprintf(int fd, const char *format, va_list ap);
extern int		ft_vfprintf(FILE *stream, const char *format, va_list ap);
extern int		ft_vprintf(const char *format, va_list ap);
extern int		ft_vsprintf(char *str, const char *format, va_list ap);
extern int		ft_vsnprintf(char *str, size_t size, const char *format,
				va_list ap);
extern ssize_t	ft_write(int filedes, const void *buf, size_t nbyte);
extern int		get_next_line(int fd, char **line);

#endif
