/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 23:33:07 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/02 23:33:09 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_chrstr(char *hay, char *needle)
{
	char *s_hay;

	s_hay = hay;
	while (*needle)
	{
		hay = s_hay;
		while (*hay)
		{
			if (*hay == *needle)
				return (*needle);
			hay++;
		}
		needle++;
	}
	return (0);
}
