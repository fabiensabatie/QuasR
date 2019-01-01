/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:00:11 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:54:21 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *haystack, char *needle)
{
	size_t needle_size;
	size_t counter;
	size_t i;

	i = 0;
	if (needle)
		needle_size = (size_t)ft_strlen(needle);
	else
		return (NULL);
	if (*needle == '\0')
		return (haystack);
	else if (needle_size)
		while (haystack[i])
		{
			counter = 0;
			while (needle[counter] == haystack[i++])
				if (++counter == needle_size)
					return (&haystack[i - counter]);
			i -= counter;
		}
	return (NULL);
}
