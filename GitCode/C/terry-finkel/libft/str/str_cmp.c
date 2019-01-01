/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:56:38 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:18:31 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline int	ft_strcmp(const char *restrict s1, const char *restrict s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	GIMME((unsigned char)*s1 - (unsigned char)*s2);
}

inline int	ft_strncmp(const char *restrict s1, const char *restrict s2,
			size_t n)
{
	if (!n)
		KTHXBYE;
	while (--n && *s1 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		++s1;
		++s2;
	}
	GIMME(*(unsigned char *)s1 - *(unsigned char *)s2);
}
