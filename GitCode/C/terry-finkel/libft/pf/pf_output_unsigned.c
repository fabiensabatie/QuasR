/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:46:32 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/13 22:35:29 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static uintmax_t			typecast(t_printf *data, t_range range)
{
	if (range == E_LONG)
		GIMME(va_arg(data->arg, unsigned long));
	else if (range == E_LONG_LONG)
		GIMME(va_arg(data->arg, unsigned long long));
	else if (range == E_INTMAX_T)
		GIMME(va_arg(data->arg, uintmax_t));
	else if (range == E_SHORT)
		GIMME((unsigned short)va_arg(data->arg, unsigned int));
	else if (range == E_CHAR)
		GIMME((unsigned char)va_arg(data->arg, unsigned int));
	else if (range == E_SIZE_T)
		GIMME(va_arg(data->arg, ssize_t));
	GIMME(va_arg(data->arg, unsigned int));
}

static void					adjust_field_width(t_printf *data, const char *base,
							uintmax_t nb, size_t len)
{
	size_t		blen;

	blen = ft_strlen(base);
	if ((base[15] == 'F' || base[15] == 'f') && nb)
	{
		if (data->field_width < 0)
			data->field_width += 2;
		else if (data->field_width >= 0)
		{
			data->field_width -= 2;
			if (len == 1 && data->field_width == -2)
				++data->field_width;
		}
	}
	else if ((blen == 8 || blen == 2) && nb)
	{
		if (data->field_width < 0)
			data->field_width += 1;
		else if (data->field_width >= 0)
			data->field_width -= 1;
	}
}

static void					left_field_width(t_printf *data, const char *base,
							int *precision, uintmax_t nb)
{
	int			field_width;
	size_t		blen;

	field_width = data->field_width;
	if (NOT_FLAG(E_ZERO, data->flags))
		while (field_width-- > *precision)
			pf_fill_buffer(data, ' ', NULL, E_PRINT);
	blen = ft_strlen(base);
	if (IS_FLAG(E_ALTERNATE, data->flags))
	{
		if (base[15] == 'F' && nb)
			pf_fill_buffer(data, 0, "0X", E_PRINT);
		else if (base[15] == 'f' && nb)
			pf_fill_buffer(data, 0, "0x", E_PRINT);
		else if (blen == 8)
			pf_fill_buffer(data, '0', NULL, E_PRINT);
		else if (blen == 2)
			pf_fill_buffer(data, 'B', NULL, E_PRINT);
	}
	if (IS_FLAG(E_ZERO, data->flags))
		while (field_width-- > *precision)
			pf_fill_buffer(data, '0', NULL, E_PRINT);
}

static void					apply_flags(t_printf *data, const char *restrict s,
							const char *restrict base, uintmax_t nb)
{
	int			k;
	int			precision;
	size_t		len;

	if (NOT_FLAG(E_PRECISION_CHANGED, data->flags))
		data->precision = 0;
	else if (data->precision >= 0)
		UNSET_FLAG(E_ZERO, data->flags);
	len = ft_strlen(s);
	if (data->precision)
		UNSET_FLAG(E_ZERO, data->flags);
	precision = MAX(data->precision, (int)len);
	if ((int)len < precision && ft_strlen(base) == 8)
		UNSET_FLAG(E_ALTERNATE, data->flags);
	if (IS_FLAG(E_ALTERNATE, data->flags))
		adjust_field_width(data, base, nb, len);
	left_field_width(data, base, &precision, nb);
	k = precision;
	while ((unsigned int)k-- > len)
		pf_fill_buffer(data, '0', NULL, E_PRINT);
	pf_fill_buffer(data, 0, s, E_PRINT);
	data->field_width = -data->field_width;
	while (data->field_width-- > precision)
		pf_fill_buffer(data, ' ', NULL, E_PRINT);
}

int							pf_output_unsigned(t_printf *data, const char *base)
{
	char			tmp[MAX_LEN_BINARY_UINTMAX_T];
	int				k;
	size_t			base_len;
	uintmax_t		n;
	uintmax_t		nb;

	base_len = ft_strlen(base);
	nb = typecast(data, data->range);
	n = nb;
	k = -1;
	if (!nb && data->precision)
	{
		tmp[++k] = '0';
		UNSET_FLAG(E_ALTERNATE, data->flags);
	}
	while (n)
	{
		tmp[++k] = base[n % base_len];
		n /= base_len;
	}
	tmp[++k] = '\0';
	apply_flags(data, ft_strrev(tmp), base, nb);
	KTHXBYE;
}
