/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buff_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:19:01 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/13 22:36:09 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static const struct s_conv		g_conv[128] =
{
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_LONG},
	{pf_output_signed, "0123456789", E_LONG}, {pf_output_char, NULL, E_CHAR},
	{pf_output_double, "0123456789", E_VOID}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_unsigned, "01234567", E_LONG},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_string, NULL, E_LONG},
	{pf_output_char, NULL, E_CHAR}, {pf_output_unsigned, "0123456789", E_LONG},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_unsigned, "0123456789ABCDEF", E_VOID},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_unsigned, "01", E_VOID},
	{pf_output_char, NULL, E_VOID}, {pf_output_signed, "0123456789", E_VOID},
	{pf_output_char, NULL, E_CHAR}, {pf_output_double, "0123456789", E_VOID},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_signed, "0123456789", E_VOID}, {pf_output_char, NULL, E_CHAR},
	{pf_output_extras, NULL, E_VOID}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_extras, NULL, E_VOID},
	{pf_output_unsigned, "01234567", E_VOID},
	{pf_output_pointer, "0123456789abcdef", E_VOID},
	{pf_output_char, NULL, E_CHAR},
	{pf_output_noprint, "0123456789abcdef", E_VOID},
	{pf_output_string, NULL, E_VOID}, {pf_output_extras, NULL, E_VOID},
	{pf_output_unsigned, "0123456789", E_VOID},
	{pf_output_extras, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_unsigned, "0123456789abcdef", E_VOID},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}, {pf_output_char, NULL, E_CHAR},
	{pf_output_char, NULL, E_CHAR}
};

static const char			*check_positional_argument(t_printf *data,
							const char *format)
{
	int			nb;
	size_t		len;

	if (data->positional == E_UNDEFINED)
	{
		nb = ft_atoi(format);
		if (nb && *(format + (len = ft_intlen(nb))) == '$')
			data->positional = E_POSITIONAL;
		else
		{
			data->positional = E_NON_POSITIONAL;
			va_copy(data->arg, data->ap);
		}
	}
	if (data->positional == E_POSITIONAL)
	{
		nb = ft_atoi(format);
		va_copy(data->arg, data->ap);
		while (--nb)
			va_arg(data->arg, void *);
		format = ft_strchr(format, '$') + 1;
	}
	GIMME(format);
}

static const char			*get_range(t_printf *data, const char *format)
{
	while (*format == 'j' || *format == 'z' || *format == 'l' || *format == 'h')
	{
		if (*format == 'j' && data->range < E_INTMAX_T)
			data->range = E_INTMAX_T;
		else if (*format == 'z' && data->range < E_SIZE_T)
			data->range = E_SIZE_T;
		else if (*format == 'l' && *(format + 1) == 'l'
			&& data->range < E_LONG_LONG && ++format)
			data->range = E_LONG_LONG;
		else if (*format == 'l')
			data->range = E_LONG;
		else if (*format == 'h' && *(format + 1) == 'h'
			&& data->range < E_CHAR && ++format)
			data->range = E_CHAR;
		else if (*format == 'h' && data->range < E_SHORT)
			data->range = E_SHORT;
		++format;
	}
	GIMME(format);
}

static const char			*find_conversion(t_printf *data, const char *format)
{
	int		k;

	format = pf_get_flags(data, format, E_SECOND);
	if (!(k = *format))
		GIMME(format);
	data->c = *format;
	if (g_conv[k].range != E_VOID && data->range != E_LONG)
		data->range = g_conv[k].range;
	g_conv[k].f(data, g_conv[k].base);
	if (data->positional == E_POSITIONAL)
		va_end(data->arg);
	GIMME(format + 1);
}

void						pf_buff_format(t_printf *data, const char *format)
{
	while (format && *format && !data->error)
	{
		while (*format == '{')
			format = pf_ansi_color(data, format, E_WIDE);
		if (*format && *format != '%')
			pf_fill_buffer(data, *format++, NULL, E_PRINT);
		else if (*format == '%' && ++format)
		{
			if (*format == '%')
				pf_fill_buffer(data, *format++, NULL, E_PRINT);
			else if (*format)
			{
				data->range = E_INT;
				data->c = 0;
				data->flags = 0;
				data->field_width = 0;
				data->precision = INT_MAX;
				format = check_positional_argument(data, format);
				format = pf_get_flags(data, format, E_FIRST);
				format = get_range(data, format);
				if (!(format = find_conversion(data, format)))
					data->error = 1;
			}
		}
	}
}
