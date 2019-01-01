/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:45:41 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/13 22:35:42 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static void			apply_field_width(t_printf *data, const char *address)
{
	int			field_width;
	size_t		len;

	field_width = data->field_width;
	len = ft_strlen(address);
	if (data->field_width > 0)
		while ((unsigned int)field_width-- > len)
			pf_fill_buffer(data, ' ', NULL, E_PRINT);
	pf_fill_buffer(data, 0, address, E_PRINT);
	if (data->field_width < 0)
	{
		field_width = -field_width;
		while ((unsigned int)field_width-- > len)
			pf_fill_buffer(data, ' ', NULL, E_PRINT);
	}
}

static void			apply_zero_width(t_printf *data, const char *s, size_t len)
{
	char		address[MAX_LEN_POINTER];
	int			k;
	int			zero_width;

	zero_width = data->field_width - len - 2;
	k = -1;
	address[++k] = '0';
	address[++k] = 'x';
	while (zero_width-- > 0)
		address[++k] = '0';
	ft_strcpy(address + k + 1, s);
	pf_fill_buffer(data, 0, address, E_PRINT);
}

static void			apply_precision(t_printf *data, const char *s,
					int precision, size_t len)
{
	char		address[MAX_LEN_POINTER];
	int			k;

	if (IS_FLAG(E_ZERO, data->flags) && data->field_width > (int)len + 2)
		GIMME(apply_zero_width(data, s, len));
	precision -= len;
	k = -1;
	address[++k] = '0';
	address[++k] = 'x';
	while (precision-- > 0)
		address[++k] = '0';
	ft_strcpy(address + k + 1, s);
	apply_field_width(data, address);
}

int					pf_output_pointer(t_printf *data, const char *base)
{
	char			tmp[MAX_LEN_INTMAX_T];
	int				k;
	int				precision;
	uintmax_t		nb;

	nb = (uintmax_t)va_arg(data->arg, intptr_t);
	k = -1;
	if (!nb && data->precision)
		tmp[++k] = '0';
	while (nb)
	{
		tmp[++k] = base[nb % 16];
		nb /= 16;
	}
	tmp[++k] = '\0';
	precision = (data->precision != INT_MAX ? data->precision : 0);
	apply_precision(data, ft_strrev(tmp), precision, ft_strlen(tmp));
	KTHXBYE;
}
