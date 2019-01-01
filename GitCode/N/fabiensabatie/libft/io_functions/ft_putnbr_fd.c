/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:49:11 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:52:06 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Ecrit l’entier n sur le descripteur de fichier fd.
*/

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nb;

	nb = n;
	if (n < 0)
	{
		nb = -n;
		write(fd, "-", 1);
	}
	if (nb > 9)
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putnbr_fd((nb % 10), fd);
	}
	else
	{
		nb += '0';
		write(fd, &nb, 1);
	}
}
