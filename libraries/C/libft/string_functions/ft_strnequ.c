/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:32:31 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:53:46 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compare lexicographiquement s1 et s2 jusqu’à n caractères maximum
** ou bien qu’un ’\0’ ait été rencontré. Si les deux chaines sont égales,
** la fonction retourne 1, ou 0 sinon.
*/

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
		if (!ft_strncmp((char*)s1, (char*)s2, n))
			return (1);
	return (0);
}
