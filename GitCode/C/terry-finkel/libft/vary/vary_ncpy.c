/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncpy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:20:26 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/21 21:50:32 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/vary.h"

inline size_t	ft_dstrncpy(char *dst, t_dstr *dstr, size_t size)
{
	char	*str;

	if (size > dstr->len)
		size = dstr->len;
	str = dstr->buff;
	ft_memmove(dst, str, size * sizeof(char));
	if (dstr->len -= size)
		ft_memmove(dstr->buff, str + size, (dstr->len + 1) * sizeof(char));
	GIMME(size);
}
