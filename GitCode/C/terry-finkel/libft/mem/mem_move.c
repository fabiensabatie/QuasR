/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:15:58 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:43:33 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"

inline void	*ft_memmove(void *restrict dst, const void *restrict src,
			size_t len)
{
	int	k;

	k = -1;
	if (src < dst)
		while ((int)--len >= 0)
			*((unsigned char *)dst + len) = *((const unsigned char *)src + len);
	else
		while ((unsigned int)++k < len)
			*((unsigned char *)dst + k) = *((const unsigned char *)src + k);
	GIMME(dst);
}
