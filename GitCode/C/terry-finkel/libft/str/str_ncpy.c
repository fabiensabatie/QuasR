/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ncpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:23:36 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:23:44 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline char	*ft_strncpy(char *restrict dst, const char *restrict src, size_t n)
{
	int	k;

	k = -1;
	while ((unsigned int)++k < n)
	{
		if (*src)
		{
			*(dst + k) = *src;
			++src;
		}
		else
			*(dst + k) = '\0';
	}
	GIMME(dst);
}
