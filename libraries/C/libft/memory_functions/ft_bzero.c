/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:25:11 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:56:32 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t len)
{
	int				i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char*)str;
	while (len--)
		s[i++] = 0;
	return (str);
}
