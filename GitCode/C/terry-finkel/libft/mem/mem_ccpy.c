/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_ccpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:17:06 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:42:35 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"

inline void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
			size_t n)
{
	int	k;

	k = -1;
	while ((unsigned int)++k < n)
	{
		if (*((unsigned char *)src + k) == (unsigned char)c)
		{
			*((unsigned char *)dst + k) = (unsigned char)c;
			GIMME(dst + k + 1);
		}
		*((unsigned char *)dst + k) = *((unsigned char *)src + k);
	}
	ZOMG;
}
