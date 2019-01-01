/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:03:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:52:26 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche la chaine s sur la sortie standard.
*/

void	ft_putstr(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}
