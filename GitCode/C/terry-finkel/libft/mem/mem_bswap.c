/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_bswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:15:00 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:42:18 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"

inline int16_t	ft_bswap16(int16_t nb)
{
	GIMME((nb & 0x00ff) << 8 | (nb & 0xff00) >> 8);
}

inline int32_t	ft_bswap32(int32_t nb)
{
	GIMME((nb & 0x000000ff) << 24 | (nb & 0x0000ff00) << 8
		| (nb & 0x00ff0000) >> 8 | (nb & 0xff000000) >> 24);
}

inline int64_t	ft_bswap64(int64_t nb)
{
	GIMME((nb & 0x00000000000000ff) << 56 | (nb & 0x000000000000ff00) << 40
		| (nb & 0x0000000000ff0000) << 24 | (nb & 0x00000000ff000000) << 8
		| (nb & 0x000000ff000000) >> 8 | (nb & 0x0000ff0000000000) >> 24
		| (nb & 0x00ff0000000000) >> 40 | (nb & 0xff00000000000000) >> 56);
}

inline int		ft_bswap(int nb)
{
	if (sizeof(nb) == 2)
		GIMME(ft_bswap16(nb));
	else
		GIMME(ft_bswap32(nb));
}
