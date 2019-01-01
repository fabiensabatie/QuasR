/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:00:11 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:54:21 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcpos(char *haystack, char needle)
{
	int i;

	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle)
			return (i);
		i++;
	}
	return (ft_strlen(haystack));
}
