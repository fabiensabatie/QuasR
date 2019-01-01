/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_nstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:26:01 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:26:07 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline char	*ft_strnstr(const char *restrict big, const char *restrict little,
			size_t n)
{
	size_t	len;

	if (!*little)
		GIMME((char *)big);
	len = ft_strlen(little);
	while (n && *big)
	{
		if (len <= n && ft_strncmp(big, little, len) == 0)
			GIMME((char *)big);
		++big;
		--n;
	}
	ZOMG;
}
