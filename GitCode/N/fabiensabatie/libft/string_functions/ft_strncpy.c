/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:20:16 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:53:43 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char *src, size_t n)
{
	size_t i;

	i = 0;
	while (*src && i < n)
		dst[i++] = *src++;
	while (i < n)
		dst[i++] = '\0';
	return (dst);
}
