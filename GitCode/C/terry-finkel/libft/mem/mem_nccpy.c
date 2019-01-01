/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_nccpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:16:47 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:43:42 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"

inline size_t	ft_memnccpy(void *restrict dst, const void *restrict src, int c,
				size_t n)
{
	int		k;
	size_t	len;

	k = -1;
	len = 0;
	while ((unsigned int)++k < n)
	{
		++len;
		if (*((unsigned char *)src + k) == (unsigned char)c)
		{
			*((unsigned char *)dst + k) = '\0';
			break ;
		}
		*((unsigned char *)dst + k) = *((unsigned char *)src + k);
	}
	*((unsigned char *)dst + k) = '\0';
	GIMME(len);
}
