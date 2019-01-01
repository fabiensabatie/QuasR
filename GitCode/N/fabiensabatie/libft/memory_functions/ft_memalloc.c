/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:29:40 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:50:48 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne une zone de mémoire “fraiche”.
** La mémoire allouée est initialisée à 0. Si l’allocation échoue,
** la fonction renvoie NULL.
*/

void	*ft_memalloc(size_t size)
{
	void	*to_assign;

	if (!(to_assign = malloc(size)))
		return (NULL);
	ft_bzero(to_assign, size);
	return (to_assign);
}
