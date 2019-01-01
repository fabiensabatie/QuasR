/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:32:45 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/08 22:32:49 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applique la fonction f à chaque caractère de la chaine de caractères
** passée en paramètre. Chaque caractère est passé par adresse à la
** fonction f afin de pouvoir être modifié si nécéssaire.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
		while (*s)
			f(s++);
}
