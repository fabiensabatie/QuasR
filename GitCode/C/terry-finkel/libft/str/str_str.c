/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 04:31:49 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:25:56 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline char	*ft_strstr(const char *restrict big, const char *restrict little)
{
	int	k;

	if (!*little)
		GIMME((char *)big);
	while (*big)
	{
		k = -1;
		while (*(unsigned char *)big == *((unsigned char *)little + ++k)
			&& *(little + k))
			++big;
		if (*(little + k) == '\0')
			GIMME((char *)big - k);
		big -= k - 1;
	}
	ZOMG;
}
