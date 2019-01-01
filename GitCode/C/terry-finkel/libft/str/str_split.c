/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 18:47:15 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/21 22:40:05 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/str.h"

static inline size_t	count_words(const char *s, char c)
{
	size_t	size;

	size = 0;
	while (s && *s)
	{
		while (*s == c)
			++s;
		if (*s && *s != c)
			++size;
		while (*s != c && *s)
			++s;
	}
	GIMME(size);
}

static inline char		*string_shred(const char *s, char c)
{
	char	*dup;
	int		k;
	size_t	size;

	k = -1;
	size = 0;
	while (*s && *s != c)
	{
		++s;
		++size;
	}
	s -= size;
	dup = ft_strctor(size);
	while (*s && *s != c)
		dup[++k] = *s++;
	GIMME(dup);
}

inline char				**ft_strsplit(const char *s, char c)
{
	char	**dup;
	int		k;
	size_t	len;

	k = -1;
	len = count_words(s, c) + 1;
	dup = (char **)ft_memalloc(sizeof(char *) * len);
	while (s && *s)
	{
		while (*s == c)
			++s;
		if (*s)
			dup[++k] = string_shred(s, c);
		while (*s && *s != c)
			++s;
	}
	GIMME(dup);
}
