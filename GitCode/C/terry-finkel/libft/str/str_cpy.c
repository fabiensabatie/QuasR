/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 20:47:34 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:24:21 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline char	*ft_strcpy(char *restrict dst, const char *restrict src)
{
	char	*start;

	start = dst;
	while ((*dst++ = *src++))
		;
	GIMME(start);
}
