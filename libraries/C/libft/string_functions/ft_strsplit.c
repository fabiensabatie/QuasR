/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:24:23 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:54:17 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne un tableau de chaines de caractères
** “fraiches” (toutes terminées par un ’\0’, le tableau également donc)
** résultant de la découpe de s selon le caractère c. Si l’allocation
** echoue, la fonction retourne NULL.
**
** Exemple : ft_strsplit("*salut*les***etudiants*", ’*’) renvoie le tableau
** ["salut", "les", "etudiants"].
*/

static	int		ft_is_sep(char c, char sep)
{
	if (c == sep || c == 0)
		return (1);
	return (0);
}

static size_t	ft_cw(char *s, char sep)
{
	size_t words;

	words = 0;
	while (*s)
	{
		if (!ft_is_sep(*s, sep) && ft_is_sep(*(s + 1), sep))
			words++;
		s++;
	}
	return (words);
}

static size_t	ft_lensep(char *s, char c)
{
	int i;

	i = 0;
	while (!ft_is_sep(*s++, c))
		i++;
	return (i);
}

static	char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	y;
	char	**res;

	i = 0;
	res = NULL;
	if (!(res = (char**)malloc(ft_cw((char *)s, c) * (sizeof(char*) + 1))))
		return (NULL);
	while (*s)
	{
		if (!ft_is_sep(*s, c))
		{
			y = 0;
			if (!(res[i] = (char*)malloc(ft_lensep((char *)s, c) + 1)))
				return (NULL);
			while (y < ft_lensep((char *)s - y, c))
				res[i][y++] = *s++;
			res[i++][y] = 0;
		}
		else
			s++;
	}
	res[i] = 0;
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;

	res = NULL;
	if (s && c)
		res = ft_split((char*)s, c);
	return (res);
}
