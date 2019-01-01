/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:07:07 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:36:00 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf/ft_printf_private.h"

inline int	ft_vasprintf(char **ret, const char *format, va_list ap)
{
	static t_printf	*data = NULL;

	if (!data && (data = (t_printf *)ft_memalloc(sizeof(t_printf))))
		data->pf_type = E_ASPRINTF;
	data->pf_buffer = ft_strctor(ASPRINTF_BUFFSIZE);
	data->pf_len = 0;
	data->pf_max_len = ASPRINTF_BUFFSIZE;
	data->non_printable = 0;
	data->positional = E_UNDEFINED;
	va_copy(data->ap, ap);
	pf_buff_format(data, format);
	*ret = data->pf_buffer;
	data->pf_len -= data->non_printable;
	va_end(data->ap);
	if (data->positional == E_NON_POSITIONAL)
		va_end(data->arg);
	GIMME(data->error ? -1 : (int)data->pf_len);
}

inline int	ft_vdprintf(int fd, const char *restrict format, va_list ap)
{
	char			buff[PRINTF_BUFFSIZE + 1];
	static t_printf	*data = NULL;

	if (!data && (data = (t_printf *)ft_memalloc(sizeof(t_printf))))
		data->pf_type = E_PRINTF;
	ft_memset(buff, '\0', PRINTF_BUFFSIZE + 1);
	data->pf_buffer = buff;
	data->fd = fd;
	data->pf_len = 0;
	data->index = 0;
	data->non_printable = 0;
	data->positional = E_UNDEFINED;
	va_copy(data->ap, ap);
	pf_buff_format(data, format);
	write(fd, data->pf_buffer, data->index);
	data->pf_len -= data->non_printable;
	va_end(data->ap);
	if (data->positional == E_NON_POSITIONAL)
		va_end(data->arg);
	GIMME(data->error ? -1 : (int)data->pf_len);
}

inline int	ft_vsnprintf(char *restrict str, size_t size,
			const char *restrict format, va_list ap)
{
	static t_printf	*data = NULL;

	if (!size)
		KTHXBYE;
	if (!data && (data = (t_printf *)ft_memalloc(sizeof(t_printf))))
		data->pf_type = E_SPRINTF;
	data->pf_buffer = str;
	data->pf_len = 0;
	data->index = size - 1;
	data->non_printable = 0;
	data->positional = E_UNDEFINED;
	va_copy(data->ap, ap);
	pf_buff_format(data, format);
	data->pf_buffer[data->pf_len] = '\0';
	data->pf_len -= data->non_printable;
	va_end(data->ap);
	if (data->positional == E_NON_POSITIONAL)
		va_end(data->arg);
	GIMME(data->error ? -1 : (int)data->pf_len);
}
