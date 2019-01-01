/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_extras.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:19:42 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/21 22:39:01 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static void			conv_k(t_printf *data)
{
	char		buff[25];
	char		*begin;
	char		*tm;
	time_t		time;

	ft_memset(buff, '\0', 25);
	time = va_arg(data->arg, time_t);
	tm = ft_ctime(&time);
	begin = tm;
	if (NOT_FLAG(E_ALTERNATE, data->flags))
		ft_strncpy(buff, tm, 24);
	else
	{
		ft_strncat(buff, tm, 3);
		ft_strcat(buff, ",");
		tm += 4;
		ft_strncat(buff, tm, 3);
		tm += 4;
		ft_strncat(buff, tm, 2);
	}
	ft_strdtor(&begin);
	pf_fill_buffer(data, 0, buff, E_PRINT);
}

static void			conv_n(t_printf *data)
{
	int		*ptr;

	ptr = (int *)va_arg(data->arg, void *);
	if (ptr)
		*ptr = (int)data->pf_len;
}

static void			conv_t(t_printf *data)
{
	char		buff[9];
	char		*tm;
	int			k;
	time_t		time;

	ft_memset(buff, '\0', 9);
	time = va_arg(data->arg, time_t);
	tm = ft_ctime(&time);
	k = 10;
	while (++k < 19)
		buff[k - 11] = tm[k];
	ft_strdtor(&tm);
	pf_fill_buffer(data, 0, buff, E_PRINT);
}

static void			conv_v(t_printf *data)
{
	char		*buff;
	char		*var;

	var = va_arg(data->arg, char *);
	if ((buff = ft_getenv(var)))
		pf_fill_buffer(data, 0, buff, E_PRINT);
}

int					pf_output_extras(t_printf *data, const char *base)
{
	(void)base;
	if (data->c == 'k')
		conv_k(data);
	else if (data->c == 'n')
		conv_n(data);
	else if (data->c == 't')
		conv_t(data);
	else
		conv_v(data);
	KTHXBYE;
}
