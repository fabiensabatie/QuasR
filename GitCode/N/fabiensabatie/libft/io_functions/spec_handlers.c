/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/19 17:04:10 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		handle_special(t_print *s)
{
	if (ft_strchr("oO", s->flag) && s->arg != 0 && ft_strlen(s->hash))
	{
		s->nb_digits += ft_strlen(s->hash);
		s->h += 1;
		s->prec -= ft_strlen(s->hash);
		fill_buffer(s, STR, (char*)s->hash, 0);
	}
	else if (ft_strchr("xX", s->flag) && (s->arg != 0 || s->ptr)
	&& ft_strlen(s->hash) && (s->nb_digits += ft_strlen(s->hash))
	&& (s->h += 1))
		fill_buffer(s, STR, (char*)s->hash, 0);
	s->hash = (s->h) ? "" : s->hash;
}

void		handle_zero(t_print *s)
{
	if (s->arg == 0 && ft_strchr("xXuUidDoO", s->flag) && !s->ip)
		return (fill_buffer(s, CHAR, 0, (char)'0'));
	if (s->arg == 0 && ft_strchr("uU", s->flag) && s->ip && s->oprec >= 1)
		fill_buffer(s, CHAR, 0, (char)'0');
	else if (s->arg == 0 && ft_strchr("xX", s->flag) && s->ip && s->oprec >= 1
	&& ft_strlen(s->hash))
		return (fill_buffer(s, CHAR, 0, (char)'0'));
	else if (s->arg == 0 && ft_strchr("oO", s->flag) && s->ip
	&& ft_strlen(s->hash))
		return (fill_buffer(s, CHAR, 0, (char)'0'));
	else if (s->arg == 0 && ft_strchr("dDxXoO", s->flag) && s->ip)
		return ;
	if (!s->h && ft_strlen(s->hash))
		fill_buffer(s, STR, (char*)s->hash, 0);
}

static void	set_color(t_print *s)
{
	if (*s->format == 'R' && (s->format += 1))
		s->color = RED;
	else if (*s->format == 'G' && (s->format += 1))
		s->color = GREEN;
	else if (*s->format == 'B' && (s->format += 1))
		s->color = BLUE;
	else if (*s->format == 'Y' && (s->format += 1))
		s->color = YELLOW;
	else if (*s->format == 'V' && (s->format += 1))
		s->color = PURPLE;
	else if (*s->format == 'M' && (s->format += 1))
		s->color = MAGENTA;
	else
		s->color = CR;
}

void		handle_bonus(t_print *s)
{
	s->color = 0;
	s->blink = 0;
	while (*s->format != s->flag && !(ft_strchr("hljz", *s->format)))
	{
		if (*s->format == '=' && (s->format += 1))
			s->blink++;
		else if (*s->format == '|' && (s->format += 1))
			set_color(s);
		else
			s->format++;
	}
}
