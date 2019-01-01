/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:44:52 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:53:15 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)), free s1 et retourne une chaine de
** caractères “fraiche” terminée par un ’\0’ résultant de la concaténation
** de s1 et s2. Si l’allocation echoue, la fonction renvoie NULL.
*/

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	char	*cat;
	int		s1len;
	int		s2len;
	int		i;
	int		y;

	cat = NULL;
	if (s1 && s2)
	{
		i = 0;
		y = 0;
		s1len = ft_strlen((char*)s1);
		s2len = ft_strlen((char*)s2);
		if (!(cat = (char*)malloc(s1len + s2len + 1)))
			return (NULL);
		while (s1[y])
			cat[i++] = (char)s1[y++];
		y = 0;
		while (s2[y])
			cat[i++] = (char)s2[y++];
		cat[i] = 0;
	}
	free((void*)s1);
	return (cat);
}
