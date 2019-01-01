/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:11:32 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:53:21 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	s1_size;
	size_t	s2_size;
	size_t	append;

	i = 0;
	s1_size = (size_t)ft_strlen(s1);
	s2_size = (size_t)ft_strlen((char*)s2);
	append = size - s1_size - 1;
	if (size < s1_size)
		return (size + s2_size);
	while (s1[i])
		i++;
	while (*s2 && append--)
		s1[i++] = *s2++;
	s1[i] = 0;
	return (s1_size + s2_size);
}
