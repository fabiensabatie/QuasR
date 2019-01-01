/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:10:24 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/13 22:36:01 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static const char			*positional_wildcard(t_printf *data,
							const char *format, t_flag flag)
{
	int			nb;
	size_t		len;

	nb = ft_atoi(format);
	len = ft_intlen(nb);
	va_copy(data->wildcard, data->ap);
	while (--nb)
		va_arg(data->wildcard, void *);
	if (flag == E_PRECISION)
		data->precision = va_arg(data->wildcard, int);
	else
		data->field_width = va_arg(data->wildcard, int);
	va_end(data->wildcard);
	GIMME(format + len + 1);
}

static const char			*get_precision(t_printf *data, const char *format)
{
	int		nb;

	while (*format == '.')
		++format;
	nb = ft_atoi(format);
	if (nb > 0)
	{
		data->precision = nb;
		SET_FLAG(E_PRECISION_CHANGED, data->flags);
		format += ft_intlen(nb);
	}
	else if (*format == '*')
	{
		++format;
		if (data->positional == E_POSITIONAL)
			format = positional_wildcard(data, format, E_PRECISION);
		else
			data->precision = va_arg(data->arg, int);
		SET_FLAG(E_PRECISION_CHANGED, data->flags);
	}
	else if ((*format < '0' || *format > '9') && !(data->precision = 0))
		SET_FLAG(E_PRECISION_CHANGED, data->flags);
	GIMME(format);
}

static const char			*get_field_width(t_printf *data, const char *format)
{
	int		nb;

	nb = ft_atoi(format);
	if (nb && *(format + ft_intlen(nb)) != '*')
	{
		while (*format == '*' && ++format)
			nb = ft_atoi(format);
		data->field_width = (IS_FLAG(E_NEGATIVE, data->flags) ? -nb : nb);
		format += ft_intlen(nb);
	}
	else if (*format == '*' || (nb && *(format + ft_intlen(nb)) == '*'))
	{
		if (nb)
			format += ft_intlen(nb);
		++format;
		if (data->positional == E_POSITIONAL)
			format = positional_wildcard(data, format, E_FIELD_WIDTH);
		else
			data->field_width = va_arg(data->arg, int);
		if (IS_FLAG(E_NEGATIVE, data->flags) && data->field_width > 0)
			data->field_width *= -1;
	}
	else
		data->field_width = 0;
	GIMME(format);
}

static const char			*get_modifiers(t_printf *data, const char *format,
							t_flag flag)
{
	while (*format == '#' || *format == ' ' || *format == '+' || *format == '-'
		|| *format == '0')
	{
		if (*format == '#')
			SET_FLAG(E_ALTERNATE, data->flags);
		else if (*format == ' ')
			SET_FLAG(E_SPACE, data->flags);
		else if (*format == '+')
			SET_FLAG(E_PLUS, data->flags);
		else if (*format == '-')
			SET_FLAG(E_NEGATIVE, data->flags);
		else if (flag == E_FIRST && *format == '0')
			SET_FLAG(E_ZERO, data->flags);
		++format;
	}
	GIMME(format);
}

const char					*pf_get_flags(t_printf *data, const char *format,
							t_flag flag)
{
	while (*format == '{')
		format = pf_ansi_color(data, format, E_NARROW);
	format = get_modifiers(data, format, flag);
	if (flag == E_FIRST)
		format = get_field_width(data, format);
	if (ft_atoi(format))
		format = get_field_width(data, format);
	if (*format == '.' && ++format)
	{
		while (*format == '0' && ++format)
			data->precision = 0;
		format = get_precision(data, format);
		if (flag == E_SECOND)
			format = get_modifiers(data, format, flag);
	}
	if (IS_FLAG(E_PLUS, data->flags))
		UNSET_FLAG(E_SPACE, data->flags);
	GIMME(format);
}
