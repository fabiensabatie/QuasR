/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/19 17:03:35 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		handle_post_digit(t_print *s, int mode, int i)
{
	if (mode == DIGITS)
	{
		if (s->ip)
		{
			s->pad_char = (s->flag == '%') ? s->pad_char : ' ';
			s->prec = ((*s->format == '*' && (*s->format += 1))) ?
			va_arg(s->ap, int) : ft_atoi(s->format);
		}
		else
			s->mfw = ((*s->format == '*' && (*s->format += 1))) ?
			va_arg(s->ap, int) : ft_atoi(s->format);
		while (ft_isdigit(*s->format))
			s->format++;
	}
	else
	{
		if (s->pad_is == AFTER && s->pad_char == ' ')
			while (s->mfw-- > i + (int)ft_strlen(s->hash) + s->wchar)
				fill_buffer(s, CHAR, 0, (char)s->pad_char);
		(s->blink) ? fill_buffer(s, STR, (char*)BLINKOFF, 0) : 0;
		(s->color) ? fill_buffer(s, STR, (char*)s->color, 0) : 0;
	}
}

void		handle_signs(t_print *s)
{
	if (s->pad_is == BEFORE && s->pad_char == ' ')
		pad(s);
	else if (s->pad_is == AFTER && s->ip)
	{
		if (s->sign == '+' && ft_strchr("dDioO", s->flag))
			(s->nb_ispos) ? fill_buffer(s, CHAR, 0, (char)'+') :
			fill_buffer(s, CHAR, 0, (char)'-');
		s->prec = (s->prec > s->nb_digits) ? (s->prec - s->nb_digits) : 0;
		while (s->prec-- > (int)ft_strlen(s->hash)
		&& (s->nb_digits += 1))
			fill_buffer(s, CHAR, 0, (char)'0');
		if (s->sign == '+' && ft_strchr("dDioO", s->flag))
			s->nb_digits++;
	}
	else if (s->pad_is == AFTER && !s->nb_ispos && (s->nb_digits += 1))
		fill_buffer(s, CHAR, 0, (char)'-');
	else if (s->pad_is == AFTER && s->sign == ' ' && (s->nb_digits += 1))
		fill_buffer(s, CHAR, 0, (char)' ');
}

static void	handle_opflag(t_print *s)
{
	if (*s->format == '#' && (s->format += 1))
	{
		if (s->flag == 'o' || s->flag == 'O')
			s->hash = "0";
		else if (ft_strchr("xX", s->flag))
			s->hash = (s->flag == 'x') ? "0x" : "0X";
	}
	else if (*s->format == '*' || (ft_isdigit(*s->format) && *s->format != '0'))
		handle_post_digit(s, DIGITS, 0);
	else if (*s->format == '-' && (s->format += 1))
		s->pad_is = AFTER;
	else if ((s->pad_is != AFTER) && *s->format == '0' && (s->format += 1)
	&& (ft_strchr("dDioOuUxX%", s->flag) && s->prec == 0))
		s->pad_char = '0';
	else if (*s->format == ' ' && !(s->sign)
	&& (ft_strchr("dDi", s->flag) && (s->format += 1)))
		s->sign = ' ';
	else if (*s->format == '+' && (ft_strchr("dDi", s->flag))
	&& (s->format += 1))
		s->sign = '+';
	else if (*s->format == '.' && (s->format += 1) && (s->ip += 1))
		handle_post_digit(s, DIGITS, 0);
	else
		s->format++;
}

static void	get_modifiers(t_print *s)
{
	s->mod = X;
	s->oprec = s->prec;
	handle_bonus(s);
	if (*s->format == 'h' && (s->format += 1))
		s->mod = (*s->format == 'h' && (s->format += 1)) ? HH : H;
	else if (*s->format == 'l' && (s->format += 1))
		s->mod = (*s->format == 'l' && (s->format += 1)) ? LL : L;
	else if (*s->format == 'j' && (s->format += 1))
		s->mod = J;
	else if (*s->format == 'z' && (s->format += 1))
		s->mod = Z;
}

void		process_flag(t_print *s)
{
	if (!(s->flag = ft_chrstr("sSpPdDioOuUxXcCb%", s->format)))
		return ;
	while (*s->format != s->flag && !(ft_strchr("hljz|=", *s->format)))
		handle_opflag(s);
	get_modifiers(s);
	if (ft_strchr("pP", s->flag))
	{
		s->hash = (s->flag == 'p') ? "0x" : "0X";
		s->flag = (s->flag == 'p') ? 'x' : 'X';
		s->ptr = 1;
		s->mod = LL;
	}
	if (ft_strchr("cs", s->flag) && s->mod == L)
		s->flag = (s->flag == 'c') ? 'C' : 'S';
	s->digits = (s->flag == 'x') ?
	"0123456789abcdef" : "0123456789ABCDEF";
	if (ft_strchr("DOU", s->flag))
		s->mod = L;
	if (ft_strchr("dDioOuUxXb", s->flag))
		handle_nb(s);
	if (ft_strchr("sScC%", s->flag))
		handle_str(s);
	s->format++;
}
