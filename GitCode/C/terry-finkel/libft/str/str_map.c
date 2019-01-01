/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 17:31:07 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:30:39 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline char	*ft_strmap(const char *s, char (*f)(char))
{
	char		*map;
	int			k;
	size_t		len;

	k = -1;
	len = ft_strlen(s);
	map = ft_strctor(len);
	while ((unsigned int)++k < len)
		*(map + k) = f(*(s + k));
	GIMME(map);
}
