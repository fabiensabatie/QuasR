/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 10:16:33 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:43:06 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"

inline int	ft_memcmp(const void *restrict s1, const void *restrict s2,
			size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			GIMME(*(unsigned char *)s1 - *(unsigned char *)s2);
		++s1;
		++s2;
	}
	KTHXBYE;
}
