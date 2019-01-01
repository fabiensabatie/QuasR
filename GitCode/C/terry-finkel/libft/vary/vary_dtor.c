/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:21:09 by nfinkel           #+#    #+#             */
/*   Updated: 2018/05/08 19:36:02 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/str.h"
#include "libft/vary.h"

inline void	ft_dstrdtor(t_dstr **adstr)
{
	if ((*adstr)->buff)
		ft_strdtor(&(*adstr)->buff);
	*adstr = NULL;
}

inline void	ft_varydtor(t_vary **avar, t_vdtor vdtor, ...)
{
	char	*ptr;
	va_list	ap;
	va_list	cpy;

	va_start(ap, vdtor);
	if ((*avar)->buff)
	{
		ptr = (char *)ft_varybegin(*avar) - (*avar)->data_size;
		while ((ptr += (*avar)->data_size) != (char *)ft_varyend(*avar))
		{
			va_copy(cpy, ap);
			vdtor(ptr, cpy);
			va_end(cpy);
		}
		ft_memdtor(&(*avar)->buff);
	}
	*avar = NULL;
	va_end(ap);
}
