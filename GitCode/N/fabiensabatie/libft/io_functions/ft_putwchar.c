/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 16:34:09 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:52:29 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wchar_t c)
{
	size_t	unisize;
	char	uni[4];

	unisize = 0;
	if (c < 0x7F)
		ft_putchar(c);
	else if (c <= 0x7FF && (unisize = 2))
	{
		uni[0] = (c >> 6) | 0xc0;
		uni[1] = (c & 0x3f) | 0x80;
	}
	else if (c <= 0xFFFF && (unisize = 3))
	{
		uni[0] = (c >> 12) | 0xe0;
		uni[1] = ((c >> 6) & 0x3f) | 0x80;
		uni[2] = (c & 0x3f) | 0x80;
	}
	else if (c <= 0x1FFFFFF && (unisize = 4))
	{
		uni[0] = (c >> 18) | 0xf0;
		uni[1] = ((c >> 12) & 0x3f) | 0x80;
		uni[2] = ((c >> 6) & 0x3f) | 0x80;
		uni[3] = (c & 0x3f) | 0x80;
	}
	write(1, uni, unisize);
}
