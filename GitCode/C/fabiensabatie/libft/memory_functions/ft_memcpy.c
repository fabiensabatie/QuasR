/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:29:08 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:51:24 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	int				i;
	unsigned char	*dest;
	unsigned char	*source;

	i = 0;
	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	while (n--)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}
