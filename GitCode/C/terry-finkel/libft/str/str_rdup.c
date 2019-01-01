/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_revcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:28:28 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:29:20 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline char	*ft_strrdup(const char *const s)
{
	char	*start;
	char	*string;
	size_t	len;

	len = ft_strlen(s);
	string = ft_strctor(len);
	start = string;
	while (len > 0)
		*string++ = s[--len];
	*string = '\0';
	GIMME(start);
}
