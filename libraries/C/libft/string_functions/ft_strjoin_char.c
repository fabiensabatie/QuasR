/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:21:37 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:53:08 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char(char const *s1, char c)
{
	char	*cat;
	int		s1len;
	int		i;

	cat = NULL;
	i = 0;
	if (s1 && c)
	{
		s1len = ft_strlen((char*)s1);
		if (!(cat = (char*)malloc(s1len + 2)))
			return (NULL);
		while (s1[i])
		{
			cat[i] = s1[i];
			i++;
		}
		cat[i++] = c;
		cat[i] = 0;
	}
	return (cat);
}
