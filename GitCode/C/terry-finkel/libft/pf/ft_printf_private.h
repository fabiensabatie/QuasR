/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:42:24 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:39:30 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H

# include "libft/api.h"
# include "libft/char.h"
# include "libft/io.h"
# include "libft/mem.h"
# include "libft/str.h"

# define ANSI_STRING_BUFFSIZE (32)
# define ASPRINTF_BUFFSIZE (128)
# define PRINTF_BUFFSIZE (4096)

# define LAST_COLOR_FLAG (22)
# define LAST_CONVERSION_FLAG (18)
# define MAX_LEN_INTMAX_T (20)
# define MAX_LEN_BINARY_UINTMAX_T (64)
# define MAX_LEN_POINTER (18)

# define FOUR_BYTES_UNICODE(x) ((x) >= 0x10000 && (x) <= 0x10FFFF)
# define THREE_BYTES_UNICODE(x) ((x) >= 0x800 && (x) < 0x10000)
# define TWO_BYTES_UNICODE(x) ((x) >= 0x80 && (x) < 0x800)
# define THREE_OR_MORE_BYTES_UNICODE(x) ((x) >= 0x800 && (x) <= 0x10FFFF)
# define TWO_OR_MORE_BYTES_UNICODE(x) ((x) >= 0x80 && (x) <= 0x10FFFF)
# define FOUR_BYTES_UNICODE_HEAD(x) ((x) >> 18 | 0xF0)
# define THREE_BYTES_UNICODE_HEAD(x) ((x) >> 12 | 0xE0)
# define THREE_BYTES_UNICODE_BODY(x) (((x) >> 12 & 0x3F) | 0x80)
# define TWO_BYTES_UNICODE_HEAD(x) ((x) >> 6 | 0xC0)
# define TWO_BYTES_UNICODE_BODY(x) (((x) >> 6 & 0x3F) | 0x80)
# define UNICODE_TAIL(x) (((x) & 0x3F) | 0x80)

typedef enum		e_flag
{
	E_ALTERNATE = 1,
	E_NEGATIVE = 2,
	E_PLUS = 4,
	E_SPACE = 8,
	E_ZERO = 16,
	E_PRECISION_CHANGED = 32,
	E_ANSI_COLOR = 64,
	E_FIRST,
	E_SECOND,
	E_PRINT,
	E_NON_PRINT,
	E_NARROW,
	E_WIDE,
	E_PRINTF,
	E_SPRINTF,
	E_ASPRINTF,
	E_UNDEFINED,
	E_NON_POSITIONAL,
	E_POSITIONAL,
	E_PRECISION,
	E_FIELD_WIDTH
}					t_flag;

typedef enum		e_range
{
	E_VOID,
	E_INT,
	E_CHAR,
	E_SHORT,
	E_SIZE_T,
	E_LONG,
	E_LONG_LONG,
	E_INTMAX_T
}					t_range;

typedef struct		s_printf
{
	t_flag			pf_type;
	char			*pf_buffer;
	int				fd;
	size_t			pf_len;
	size_t			pf_max_len;
	size_t			index;
	size_t			non_printable;
	t_range			range;
	bool			color_multiple_flags;
	char			ansi_colors[ANSI_STRING_BUFFSIZE];
	char			c;
	int8_t			error;
	int8_t			flags;
	int				field_width;
	int				precision;
	t_flag			positional;
	va_list			ap;
	va_list			arg;
	va_list			wildcard;
}					t_printf;

struct				s_color
{
	char			letter;
	char			code;
};

struct				s_conv
{
	int				(*f)(t_printf *, const char *);
	const char		*base;
	t_range			range;
};

void				pf_fill_buffer(t_printf *data, const char filler,
					const char *s_filler, t_flag flag);
const char			*pf_get_flags(t_printf *data, const char *format,
					t_flag flag);
const char			*pf_ansi_color(t_printf *data, const char *format,
					t_flag flag);
void				pf_buff_format(t_printf *data, const char *format);
int					pf_output_char(t_printf *data, const char *base);
int					pf_output_double(t_printf *data, const char *base);
int					pf_output_extras(t_printf *data, const char *base);
int					pf_output_noprint(t_printf *data, const char *base);
int					pf_output_pointer(t_printf *data, const char *base);
int					pf_output_signed(t_printf *data, const char *base);
int					pf_output_string(t_printf *data, const char *base);
int					pf_output_unsigned(t_printf *data, const char *base);

#endif
