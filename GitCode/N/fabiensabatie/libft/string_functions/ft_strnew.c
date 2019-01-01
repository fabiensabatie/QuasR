/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:16:00 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:53:50 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne une chaine de caractère “fraiche”
** terminée par un ’\0’. Chaque caractère de la chaine est initialisé à
** ’\0’. Si l’allocation echoue, la fonction renvoie NULL.
*/

char	*ft_strnew(size_t size)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (!(newstr = (char*)malloc(size + 1)))
		return (NULL);
	while (i <= size)
		newstr[i++] = 0;
	return (newstr);
}
