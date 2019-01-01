/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:17 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:55:31 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		pad(t_print *s)
{
	s->prec = (s->prec > s->nb_digits) ? (s->prec - s->nb_digits) : 0;
	if (s->sign == '+' || s->sign == ' ')
		s->nb_digits++;
	s->mfw = (s->mfw > (s->prec + s->nb_digits)) ?
	(s->mfw - s->prec - s->nb_digits) : 0;
	s->mfw -= (s->ptr && s->arg == 0) ? ft_strlen(s->hash) : 0;
	if (s->pad_char == ' ' && ft_strchr("xXoO", s->flag) && s->arg == 0)
		while (s->mfw-- > 0)
			fill_buffer(s, CHAR, 0, (char)s->pad_char);
	else if (s->pad_char == ' ')
		while (s->mfw-- > (int)ft_strlen(s->hash))
			fill_buffer(s, CHAR, 0, (char)s->pad_char);
	handle_special(s);
	if (s->sign == ' ' && s->nb_ispos)
		fill_buffer(s, CHAR, 0, (char)s->sign);
	else if (s->sign == '+' && ft_strchr("dDioO", s->flag))
		(s->nb_ispos) ? fill_buffer(s, CHAR, 0, (char)'+') :
		fill_buffer(s, CHAR, 0, (char)'-');
	if (s->pad_char == '0')
		while (s->mfw-- > (int)ft_strlen(s->hash))
			fill_buffer(s, CHAR, 0, (char)s->pad_char);
	while (s->prec-- > (int)ft_strlen(s->hash))
		fill_buffer(s, CHAR, 0, (char)'0');
}

static int	get_base(t_print *s)
{
	if (s->flag == 'o' || s->flag == 'O')
		return (8);
	else if (s->flag == 'x' || s->flag == 'X')
		return (16);
	else if (s->flag == 'b')
		return (2);
	else
		return (10);
}

static void	handle_pre(t_print *s)
{
	handle_signs(s);
	(s->blink) ? fill_buffer(s, STR, (char*)BLINKON, 0) : 0;
	(s->color) ? fill_buffer(s, STR, (char*)s->color, 0) : 0;
	if (s->pad_is == BEFORE && s->pad_char == '0' &&
	ft_strchr("idDxXoOuU", s->flag))
	{
		if (ft_strlen(s->hash) && s->arg != 0
		&& (s->nb_digits += ft_strlen(s->hash)))
			fill_buffer(s, STR, (char*)s->hash, 0);
		s->hash = "";
		pad(s);
	}
	handle_zero(s);
}

static void	nb_print(t_print *s, intmax_t nbr)
{
	intmax_t	res[264];
	uintmax_t	n;
	int			i;

	i = 0;
	s->arg = nbr;
	s->nb_ispos = ((nbr >= 0)) ? 1 : 0;
	s->nb_ispos = (ft_strchr("xXoOuU", s->flag)) ? 1 : s->nb_ispos;
	n = nbr;
	if ((!s->nb_ispos) && (s->sign = '+'))
		n = -nbr;
	if (ft_strchr("xXoOuUb", s->flag))
		n = (unsigned long)nbr;
	while (n > 0)
	{
		res[i++] = ft_abs(n % s->base);
		n /= s->base;
	}
	s->nb_digits = i ? i : 1;
	if (s->arg == 0 && ft_strchr("xXoOdD", s->flag) && s->ip)
		s->nb_digits = 0;
	handle_pre(s);
	while (i--)
		fill_buffer(s, CHAR, 0, (char)s->digits[res[i]]);
	handle_post_digit(s, POST, s->nb_digits);
}

void		handle_nb(t_print *s)
{
	intmax_t arg;

	arg = va_arg(s->ap, intmax_t);
	s->base = get_base(s);
	if (s->mod == H)
		(ft_strchr("dDi", s->flag)) ? nb_print(s, (short int)arg) :
		nb_print(s, (unsigned short)arg);
	if (s->mod == HH)
		(ft_strchr("dDi", s->flag)) ? nb_print(s, (signed char)arg) :
		nb_print(s, (unsigned char)arg);
	if (s->mod == L)
		(ft_strchr("dDi", s->flag)) ? nb_print(s, (long)arg) :
		nb_print(s, (unsigned long)arg);
	if (s->mod == LL)
		(ft_strchr("dDi", s->flag)) ? nb_print(s, (long long)arg) :
		nb_print(s, (unsigned long long)arg);
	if (s->mod == J)
		(ft_strchr("dDi", s->flag)) ? nb_print(s, (intmax_t)arg) :
		nb_print(s, (uintmax_t)arg);
	if (s->mod == Z)
		(ft_strchr("dDi", s->flag)) ? nb_print(s, arg) :
		nb_print(s, (size_t)arg);
	if (s->mod == X)
		(ft_strchr("dDi", s->flag)) ? nb_print(s, (int)arg) :
		nb_print(s, (unsigned int)arg);
}
