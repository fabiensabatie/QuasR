/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:18:07 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:43:50 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"

inline void	*ft_memset(void *b, int c, size_t len)
{
	int	k;

	k = -1;
	while ((unsigned int)++k < len)
		*((unsigned char *)b + k) = (unsigned char)c;
	GIMME(b);
}
