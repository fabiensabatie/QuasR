/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 20:01:07 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/21 21:37:03 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline char		*ft_strcat(char *restrict dst, const char *restrict src)
{
	char	*d;

	d = ft_strchr(dst, '\0');
	while ((*d++ = *src++))
		;
	GIMME(dst);
}

inline char		*ft_strncat(char *restrict s1, const char *restrict s2,
				size_t n)
{
	int		k;
	size_t	len;

	k = -1;
	len = ft_strlen(s1);
	while ((unsigned int)++k < n && *(s2 + k))
		*(s1 + len++) = *(s2 + k);
	*(s1 + len) = '\0';
	GIMME(s1);
}

inline size_t	ft_strlcat(char *restrict dst, const char *restrict src,
				size_t n)
{
	int		k;
	size_t	len_dst;
	size_t	len_src;
	size_t	p;

	k = -1;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	p = len_dst - 1;
	if (n < len_dst + 1)
		GIMME(len_src + n);
	while (++p < n - 1)
		*(dst + p) = *(src + ++k);
	*(dst + p) = '\0';
	GIMME(len_dst + len_src);
}
