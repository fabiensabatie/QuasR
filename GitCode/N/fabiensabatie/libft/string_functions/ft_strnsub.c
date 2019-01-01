/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:17:25 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:54:05 by fsabatie         ###   ########.fr       */
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

char	*ft_strnsub(char const *s, int n)
{
	char	*toreturn;
	int		i;

	i = 0;
	toreturn = NULL;
	if (s)
	{
		while (s[i] && i < n)
			i++;
		if (!(toreturn = (char*)malloc(i + 1)))
			return (NULL);
		i = 0;
		while (s[i] && i < n)
		{
			toreturn[i] = s[i];
			i++;
		}
		toreturn[i] = 0;
	}
	return (toreturn);
}
