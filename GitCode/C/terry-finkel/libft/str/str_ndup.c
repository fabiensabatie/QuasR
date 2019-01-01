/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ndup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:24:25 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:24:33 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = ft_strctor(n);
	str = ft_strncpy(str, (char *)s, n);
	str[n] = '\0';
	GIMME(str);
}
