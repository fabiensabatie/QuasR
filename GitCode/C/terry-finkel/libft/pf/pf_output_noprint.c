/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_noprint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:45:29 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:39:47 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static void			copy_string(char *restrict dst, const char *restrict src,
					const char *base, int precision)
{
	while (*src && precision)
	{
		if (ft_isprint(*src) == false)
		{
			*dst++ = '\\';
			*dst++ = '0';
			*dst++ = 'x';
			*dst++ = base[(*src / 16) % 16];
			*dst++ = base[*src % 16];
			precision -= 4;
		}
		else
			*dst++ = *src;
		++src;
		--precision;
	}
}

static void			apply_left_field_width(t_printf *data, int precision)
{
	char		filler;
	int			field_width;

	filler = (IS_FLAG(E_ZERO, data->flags) ? '0' : ' ');
	field_width = data->field_width;
	while (field_width-- > precision)
		pf_fill_buffer(data, filler, NULL, E_PRINT);
}

static void			apply_right_field_width(t_printf *data, int precision)
{
	int		field_width;

	field_width = -data->field_width;
	while (field_width-- > precision)
		pf_fill_buffer(data, ' ', NULL, E_PRINT);
}

int					pf_output_noprint(t_printf *data, const char *base)
{
	char		*begin;
	char		*string;
	int			precision;
	size_t		len;

	string = va_arg(data->arg, char *);
	string = (!string ? "(null)" : string);
	begin = string;
	precision = 0;
	len = 0;
	while (*string && ++string && ++len)
	{
		if (ft_isprint(*(string - 1)) && (int)len <= data->precision)
			++precision;
		if (!ft_isprint(*(string - 1)) && (len += 4))
			if ((int)len <= data->precision)
				precision += 5;
	}
	string = ft_strctor(precision);
	copy_string(string, begin, base, precision);
	apply_left_field_width(data, precision);
	pf_fill_buffer(data, 0, string, E_PRINT);
	apply_right_field_width(data, precision);
	free(string);
	KTHXBYE;
}
