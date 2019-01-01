/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 23:33:07 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/03 20:31:14 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_chrcstr(char *hay, char *needle, char c)
{
	char *s_hay;

	s_hay = hay;
	while (*needle)
	{
		if (*needle == c)
			return (0);
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
