/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:05:36 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:54:35 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne une copie de la chaine passée en
** paramètre sans les espaces blancs au debut et à la fin de cette chaine.
** On considère comme espaces blancs les caractères ’ ’, ’\n’ et ’\t’.
** Si s ne contient pas d’espaces blancs au début ou à la fin, la fonction
** renvoie une copie de s. Si l’allocation echoue, la fonction renvoie NULL.
*/

char	*ft_strtrim(char const *s)
{
	char			*copy;
	unsigned int	start;
	unsigned int	end;

	copy = NULL;
	start = 0;
	if (s)
	{
		end = ft_strlen((char*)s) - 1;
		while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
			start++;
		if (start == end + 1)
			return (ft_strnew(0));
		while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
			end--;
		copy = ft_strsub(s, start, end - start + 1);
	}
	return (copy);
}
