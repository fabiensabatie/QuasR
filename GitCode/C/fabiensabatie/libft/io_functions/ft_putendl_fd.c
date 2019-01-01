/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:47:13 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/08 23:47:14 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Ecrit la chaine s sur le descripteur de fichier fd suivi d’un ’\n’.
*/

void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd((char *)s, fd);
	ft_putchar_fd('\n', fd);
}
