/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:59:05 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:25:16 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline char	*ft_strsub(char *s, unsigned int start, size_t len, bool free)
{
	char	*begin;
	char	*sub;
	int		k;

	begin = s;
	sub = ft_strctor(len);
	s += start;
	k = -1;
	while ((unsigned int)++k < len)
		*(sub + k) = *(s + k);
	s = begin;
	if (free == true)
		ft_strdtor(&s);
	GIMME(sub);
}
