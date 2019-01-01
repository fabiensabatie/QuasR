/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_mapi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:30:43 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:30:52 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char		*map;
	int			k;
	size_t		len;

	len = ft_strlen(s);
	map = ft_strctor(len);
	k = -1;
	while ((unsigned int)++k < len)
		*(map + k) = f(k, *(s + k));
	GIMME(map);
}
