/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:49:23 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cat_buffer(t_print *s, char *str)
{
	char	*cat;
	size_t	i;
	size_t	y;
	size_t	slen;

	cat = NULL;
	i = 0;
	y = 0;
	slen = ft_strlen((char*)str);
	if (!(cat = (char*)malloc(s->cnt + slen + 1)))
		return ;
	while (y < s->cnt)
		cat[i++] = s->buffer[y++];
	y = 0;
	while (y < slen)
		cat[i++] = str[y++];
	cat[i] = 0;
	free(s->buffer);
	s->buffer = cat;
	s->cnt += slen;
}

static void	add_zero(t_print *s)
{
	char	*cpy;
	int		i;

	i = 0;
	if (!(cpy = (char*)malloc(s->cnt + 2)))
		return ;
	while (i < (int)s->cnt)
	{
		cpy[i] = s->buffer[i];
		i++;
	}
	cpy[i++] = '\0';
	cpy[i] = '\0';
	free(s->buffer);
	s->buffer = cpy;
	s->cnt++;
}

void		wchar_tobuffer(t_print *s, wchar_t c)
{\
	if ((((c < 0 || c > 0x10ffff)
	|| (MB_CUR_MAX == 1 && c > 0xff && c <= 0x10ffff)
	|| (c >= 0xd800 && c <= 0xdfff))) && (s->cnt = -1))
		return ;
	else if (c < 0x7F)
		fill_buffer(s, CHAR, 0, (char)c);
	else if (c <= 0x7FF && (s->wchar = 1))
	{
		fill_buffer(s, CHAR, 0, (char)((c >> 6) | 0xc0));
		fill_buffer(s, CHAR, 0, (char)((c & 0x3f) | 0x80));
	}
	else if (c <= 0xFFFF && (s->wchar = 2))
	{
		fill_buffer(s, CHAR, 0, (char)((c >> 12) | 0xe0));
		fill_buffer(s, CHAR, 0, (char)(((c >> 6) & 0x3f) | 0x80));
		fill_buffer(s, CHAR, 0, (char)((c & 0x3f) | 0x80));
	}
	else if (c <= 0x1FFFFFF && (s->wchar = 3))
	{
		fill_buffer(s, CHAR, 0, (char)((c >> 18) | 0xf0));
		fill_buffer(s, CHAR, 0, (char)(((c >> 12) & 0x3f) | 0x80));
		fill_buffer(s, CHAR, 0, (char)(((c >> 6) & 0x3f) | 0x80));
		fill_buffer(s, CHAR, 0, (char)((c & 0x3f) | 0x80));
	}
}

void		fill_buffer(t_print *s, int mode, char *str, char c)
{
	char	*n_str;

	if (mode == CHAR && c)
	{
		n_str = ft_chartostr(c);
		cat_buffer(s, n_str);
		free(n_str);
	}
	else if (mode == CHAR && !c)
		add_zero(s);
	else if (mode == STR)
		cat_buffer(s, str);
}
