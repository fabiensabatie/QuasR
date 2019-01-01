/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:38:49 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:37:35 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io.h"

inline int	ft_sprintf(char *restrict str, const char *restrict format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = ft_vsprintf(str, format, ap);
	va_end(ap);
	GIMME(len);
}

inline int	ft_snprintf(char *restrict str, size_t size,
			const char *restrict format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = ft_vsnprintf(str, size, format, ap);
	va_end(ap);
	GIMME(len);
}

inline int	ft_vprintf(const char *restrict format, va_list ap)
{
	GIMME(ft_vdprintf(STDOUT_FILENO, format, ap));
}

inline int	ft_vfprintf(FILE *restrict stream, const char *restrict format,
			va_list ap)
{
	GIMME(ft_vdprintf(stream->_file, format, ap));
}

inline int	ft_vsprintf(char *restrict str, const char *restrict format,
			va_list ap)
{
	GIMME(ft_vsnprintf(str, INT_MAX + 1, format, ap));
}
