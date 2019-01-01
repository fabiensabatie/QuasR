/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 14:48:31 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:17:18 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			GIMME((char *)s);
		++s;
	}
	GIMME(!(char)c ? (char *)s : NULL);
}
