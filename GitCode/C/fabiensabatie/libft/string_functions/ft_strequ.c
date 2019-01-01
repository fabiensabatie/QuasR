/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:29:08 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/08 23:29:09 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compare lexicographiquement s1 et s2. Si les deux chaines sont égales,
** la fonction retourne 1, ou 0 sinon.
*/

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
		if (!ft_strcmp((char*)s1, (char*)s2))
			return (1);
	return (0);
}
