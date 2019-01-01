/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:30:52 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:43:15 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"

inline void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	int	k;

	k = -1;
	while ((unsigned int)++k < n)
		*((unsigned char *)dst + k) = *((unsigned char *)src + k);
	GIMME(dst);
}
