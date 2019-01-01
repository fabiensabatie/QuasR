/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/19 17:04:13 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	handle_pre(t_print *s, int len)
{
	if (s->blink)
		fill_buffer(s, STR, (char*)BLINKON, 0);
	if (s->color)
		fill_buffer(s, STR, (char*)s->color, 0);
	s->mfw = (s->mfw > len) ? (s->mfw - len) : 0;
	if (s->pad_is == BEFORE)
		while (s->mfw-- > 0)
			fill_buffer(s, CHAR, 0, (char)s->pad_char);
}

static void	handle_char(t_print *s)
{
	handle_pre(s, 1);
	if (s->flag == 'c' && s->mod != L)
		fill_buffer(s, CHAR, 0, (char)va_arg(s->ap, int));
	else if (s->flag == 'c' && s->mod == L)
		wchar_tobuffer(s, va_arg(s->ap, wchar_t));
	else if (s->flag == 'C')
		wchar_tobuffer(s, va_arg(s->ap, wchar_t));
	else if (s->flag == '%')
		fill_buffer(s, CHAR, 0, (char)'%');
	handle_post_digit(s, POST, 0);
}

static void	handle_wstr(t_print *s)
{
	wchar_t *arg;

	arg = NULL;
	if (!(arg = (wchar_t*)(va_arg(s->ap, wchar_t*))))
		arg = L"(null)";
	if (s->ip)
		arg = ((int)ft_wstrlen((wchar_t*)arg) > s->prec) ?
		(wchar_t*)ft_wstrnsub((wchar_t*)arg, s->prec) : arg;
	handle_pre(s, ft_wstrlen((wchar_t*)arg));
	while ((wchar_t)*arg != '\0')
	{
		wchar_tobuffer(s, *arg++);
		if ((int)s->cnt == -1)
			return ;
	}
	handle_post_digit(s, POST, 0);
}

void		handle_str(t_print *s)
{
	char *arg;

	arg = NULL;
	if (s->flag == 's' && s->mod != L)
	{
		if (!(arg = (char*)(va_arg(s->ap, char*))))
			arg = "(null)";
		if (s->ip)
			arg = ((int)ft_strlen(arg) > s->prec) ?
			ft_strnsub(arg, s->prec) : arg;
		handle_pre(s, ft_strlen(arg));
		fill_buffer(s, STR, (char*)arg, 0);
		handle_post_digit(s, POST, 0);
	}
	else if (s->flag == 's' && s->mod == L)
		handle_wstr(s);
	else if (s->flag == 'S')
		handle_wstr(s);
	else
		handle_char(s);
}
