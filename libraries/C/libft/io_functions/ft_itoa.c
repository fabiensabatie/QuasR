/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:37:27 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/09 16:37:28 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne une chaine de caractères “fraiche”
** terminée par un ’\0’ représentant l’entier n passé en paramètre. Les
** nombres négatifs doivent être gérés. Si l’al- location échoue, la
** fonction renvoie NULL.
*/

char	*ft_itoa(int n)
{
	char		*res;
	char		toconvert;
	long long	nbr;

	if (!(res = ft_strnew(0)))
		return (NULL);
	nbr = (long long)ft_abs(n);
	while (nbr > 9)
	{
		toconvert = (char)(nbr % 10) + '0';
		res = ft_strjoin_char(res, (char)toconvert);
		nbr /= 10;
	}
	res = ft_strjoin_char(res, ((char)nbr + '0'));
	res = ft_strrev(res);
	if (n < 0)
		res = ft_strjoin("-", res);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (res);
}
