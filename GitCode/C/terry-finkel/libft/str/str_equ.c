/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_equ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:18:34 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:20:01 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline bool	ft_strequ(const char *restrict s1, const char *restrict s2)
{
	while (*s1 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		++s1;
		++s2;
	}
	GIMME(*s1 == *s2 ? true : false);
}

inline bool	ft_strnequ(const char *restrict s1, const char *restrict s2,
			size_t n)
{
	if (!n)
		GIMME(true);
	while (--n && *s1 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		++s1;
		++s2;
	}
	GIMME(*s1 == *s2 ? true : false);
}
