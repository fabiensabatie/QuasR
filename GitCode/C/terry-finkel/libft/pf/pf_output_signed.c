/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:46:04 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/13 22:35:38 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static intmax_t			typecast(t_printf *data, t_range range)
{
	if (range == E_LONG)
		GIMME(va_arg(data->arg, long));
	else if (range == E_LONG_LONG)
		GIMME(va_arg(data->arg, long long));
	else if (range == E_INTMAX_T)
		GIMME(va_arg(data->arg, intmax_t));
	else if (range == E_SHORT)
		GIMME((short)va_arg(data->arg, int));
	else if (range == E_CHAR)
		GIMME((char)va_arg(data->arg, int));
	else if (range == E_SIZE_T)
		GIMME(va_arg(data->arg, size_t));
	GIMME(va_arg(data->arg, int));
}

static void				left_field_width(t_printf *data, int *precision,
						int neg)
{
	int		field_width;

	field_width = data->field_width - (IS_FLAG(E_SPACE, data->flags) ? 1 : 0);
	if (neg)
	{
		if (IS_FLAG(E_ZERO, data->flags) && ++*precision)
			pf_fill_buffer(data, '-', NULL, E_PRINT);
		else
			--field_width;
	}
	if (!neg && IS_FLAG(E_PLUS, data->flags) && NOT_FLAG(E_ZERO, data->flags))
		--field_width;
	if (NOT_FLAG(E_ZERO, data->flags))
		while (field_width-- > *precision)
			pf_fill_buffer(data, ' ', NULL, E_PRINT);
	if (!neg && IS_FLAG(E_PLUS, data->flags) && ++*precision)
		pf_fill_buffer(data, '+', NULL, E_PRINT);
	if (IS_FLAG(E_ZERO, data->flags))
		while (field_width-- > *precision)
			pf_fill_buffer(data, '0', NULL, E_PRINT);
	if (neg && NOT_FLAG(E_ZERO, data->flags) && ++*precision)
		pf_fill_buffer(data, '-', NULL, E_PRINT);
}

static void				apply_flags(t_printf *data, const char *s, intmax_t nb)
{
	int			k;
	int			precision;
	size_t		len;

	len = ft_strlen(s);
	if (data->precision > 0)
		UNSET_FLAG(E_ZERO, data->flags);
	precision = MAX(data->precision, (int)len);
	k = precision;
	if (nb >= 0 && IS_FLAG(E_SPACE, data->flags))
		pf_fill_buffer(data, ' ', NULL, E_PRINT);
	left_field_width(data, &precision, (nb < 0 ? 1 : 0));
	if (nb >= 0 && IS_FLAG(E_SPACE, data->flags))
		++precision;
	while ((unsigned int)k-- > len)
		pf_fill_buffer(data, '0', NULL, E_PRINT);
	pf_fill_buffer(data, 0, s, E_PRINT);
	data->field_width = -data->field_width;
	while (data->field_width-- > precision)
		pf_fill_buffer(data, ' ', NULL, E_PRINT);
}

int						pf_output_signed(t_printf *data, const char *base)
{
	char			tmp[MAX_LEN_INTMAX_T];
	int				k;
	intmax_t		n;
	intmax_t		nb;

	nb = typecast(data, data->range);
	k = -1;
	if (!nb && data->precision)
		tmp[++k] = '0';
	n = nb;
	while (n)
	{
		tmp[++k] = base[ABS(n % 10)];
		n /= 10;
	}
	tmp[++k] = '\0';
	if (NOT_FLAG(E_PRECISION_CHANGED, data->flags))
		data->precision = 0;
	else if (data->precision >= 0)
		UNSET_FLAG(E_ZERO, data->flags);
	apply_flags(data, ft_strrev(tmp), nb);
	KTHXBYE;
}
