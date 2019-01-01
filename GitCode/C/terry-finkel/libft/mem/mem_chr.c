/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:22:44 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:42:43 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"

inline void	*ft_memchr(const void *s, int c, size_t n)
{
	int	k;

	k = -1;
	while ((unsigned int)++k < n)
		if (*((unsigned char *)s + k) == (unsigned char)c)
			GIMME((void *)s + k);
	ZOMG;
}
