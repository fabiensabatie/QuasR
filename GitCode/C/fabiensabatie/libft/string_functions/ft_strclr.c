/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:31:15 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/08 22:31:16 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Assigne la valeur ’\0’ à tous les caractères de la chaine passée
** en paramètre.
*/

void	ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = 0;
}
