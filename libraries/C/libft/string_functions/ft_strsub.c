/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:17:25 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:54:30 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne la copie “fraiche” d’un tronçon
** de la chaine de caractères passée en paramètre. Le tronçon commence
** l’index start et à pour longueur len. Si start et len ne désignent
** pas un tronçon de chaine valide, le comportement est indéterminé.
** Si l’allocation échoue, la fonction renvoie NULL.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*toreturn;
	int		i;

	i = 0;
	toreturn = NULL;
	if (s)
	{
		toreturn = (char*)s + start;
		if (!(toreturn = (char*)malloc(len + 1)))
			return (NULL);
		while (s[start])
			toreturn[i++] = s[start++];
		toreturn[len] = 0;
	}
	return (toreturn);
}
