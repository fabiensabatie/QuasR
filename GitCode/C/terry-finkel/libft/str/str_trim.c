/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_trim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:25:20 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:29:48 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

static inline size_t	value_to_trim(const char *restrict s1,
						const char *restrict s2)
{
	size_t	trim;
	size_t	len;

	trim = 0;
	len = ft_strlen(s1);
	while (IS_WHITESPACE(*s1))
	{
		++trim;
		++s1;
	}
	while (IS_WHITESPACE(*s2))
	{
		++trim;
		++s2;
	}
	GIMME(trim == len * 2 ? len : trim);
}

inline char				*ft_strtrim(char *s, bool free)
{
	char	*begin;
	char	*rev;
	char	*trim;
	int		k;
	size_t	len;

	begin = s;
	rev = ft_strrdup(s);
	k = -1;
	len = ft_strlen(s) - value_to_trim(s, rev);
	ft_strclr(rev);
	trim = ft_strctor(len);
	while (IS_WHITESPACE(*s))
		++s;
	while (len--)
	{
		*(trim + ++k) = *s;
		++s;
	}
	s = begin;
	if (free == true)
		ft_strdtor(&s);
	GIMME(trim);
}
