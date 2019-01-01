/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:46:19 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/21 22:38:50 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static size_t			get_wide_length(t_printf *data, const wchar_t *s)
{
	size_t				len;
	unsigned int		precision;

	len = 0;
	precision = 0;
	while (*s)
	{
		if ((int)(*s) >= 0 && (int)(*s) < 0x100 && ++len)
			if ((int)len <= data->precision)
				precision += 1;
		if (FOUR_BYTES_UNICODE((int)(*s)) && (len += 4))
			if ((int)len <= data->precision)
				precision += 4;
		if (THREE_BYTES_UNICODE((int)(*s)) && (len += 3))
			if ((int)len <= data->precision)
				precision += 3;
		if (TWO_BYTES_UNICODE((int)(*s)) && (len += 2))
			if ((int)len <= data->precision)
				precision += 2;
		++s;
	}
	data->precision = precision;
	GIMME(len);
}

static int				copy_wstring(char *restrict s,
						const wchar_t *restrict w, int precision)
{
	while (*w && precision--)
	{
		if (*w < 0 || *w > 0x10ffff || (*w >= 0xd800 && *w <= 0xdfff)
			|| (MB_CUR_MAX == 1 && *w > 0xff && *w <= 0x10ffff))
			ONOES;
		if (*w >= 0 && (*w < 128 || (*w < 0x100 && MB_CUR_MAX == 1)))
			*s++ = *w;
		if (FOUR_BYTES_UNICODE(*w) && (*s++ = FOUR_BYTES_UNICODE_HEAD(*w)))
			*s++ = THREE_BYTES_UNICODE_BODY(*w);
		if (THREE_BYTES_UNICODE(*w))
			*s++ = THREE_BYTES_UNICODE_HEAD(*w);
		if (THREE_OR_MORE_BYTES_UNICODE(*w))
			*s++ = TWO_BYTES_UNICODE_BODY(*w);
		if (TWO_BYTES_UNICODE(*w) && MB_CUR_MAX > 1)
			*s++ = TWO_BYTES_UNICODE_HEAD(*w);
		if (TWO_OR_MORE_BYTES_UNICODE(*w) && MB_CUR_MAX > 1)
			*s++ = UNICODE_TAIL(*w);
		++w;
	}
	KTHXBYE;
}

static void				apply_left_field_width(t_printf *data, int precision)
{
	char		filler;
	int			field_width;

	if (data->field_width < 0)
		UNSET_FLAG(E_ZERO, data->flags);
	filler = (IS_FLAG(E_ZERO, data->flags) ? '0' : ' ');
	field_width = data->field_width;
	if (IS_FLAG(E_ZERO, data->flags) && IS_FLAG(E_ANSI_COLOR, data->flags))
		pf_fill_buffer(data, 0, data->ansi_colors, E_NON_PRINT);
	while (field_width-- > precision)
		pf_fill_buffer(data, filler, NULL, E_PRINT);
}

static void				apply_precision(t_printf *data, const char *s,
						int precision)
{
	char		adjusted_string[precision + 1];
	int			field_width;
	int			k;

	k = -1;
	while (++k < precision)
		adjusted_string[k] = s[k];
	adjusted_string[precision] = '\0';
	if (NOT_FLAG(E_ZERO, data->flags) && IS_FLAG(E_ANSI_COLOR, data->flags))
		pf_fill_buffer(data, 0, data->ansi_colors, E_NON_PRINT);
	pf_fill_buffer(data, 0, adjusted_string, E_PRINT);
	field_width = -data->field_width;
	while (field_width-- > precision)
		pf_fill_buffer(data, ' ', NULL, E_PRINT);
}

int						pf_output_string(t_printf *data, const char *string)
{
	int			precision;
	wchar_t		*wide_string;

	string = NULL;
	wide_string = NULL;
	if (data->precision < 0)
		data->precision = INT_MAX;
	if (data->range == E_LONG && (wide_string = va_arg(data->arg, wchar_t *)))
	{
		string = ft_strctor(get_wide_length(data, wide_string));
		if (copy_wstring((char *)string, wide_string, data->precision) == -1)
		{
			free((char *)string);
			ONOES;
		}
	}
	else if (data->range != E_LONG)
		string = va_arg(data->arg, char *);
	string = (!string ? "(null)" : string);
	precision = MIN(data->precision, (int)ft_strlen(string));
	apply_left_field_width(data, precision);
	apply_precision(data, string, precision);
	if (data->range == E_LONG && wide_string)
		free((char *)string);
	KTHXBYE;
}
