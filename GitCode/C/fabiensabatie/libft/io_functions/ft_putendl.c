/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:36:11 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/08 23:36:12 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche la chaine s sur la sortie standard suivi d’un ’\n’.
*/

void	ft_putendl(char const *s)
{
	ft_putstr((char *)s);
	ft_putchar('\n');
}
