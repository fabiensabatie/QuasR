/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:00:11 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:54:21 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrpos(char *haystack, char needle)
{
	int i;

	i = ft_strlen(haystack) - 1;
	while (haystack[i])
	{
		if (haystack[i] == needle)
			return (i);
		i--;
	}
	return (ft_strlen(haystack));
}
