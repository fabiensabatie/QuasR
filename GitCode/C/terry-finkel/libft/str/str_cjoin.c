/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cjoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:31:58 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:32:12 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline char	*ft_strcjoin(char *restrict s1, const char *restrict s2,
			const char c, bool free)
{
	char	*join;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = ft_strctor(len_s1 + len_s2 + 1);
	join = ft_strcpy(join, s1);
	join = ft_strncat(join, s2, len_s2);
	join[len_s1 + len_s2] = c;
	if (free == true)
		ft_strdtor((char **)&s1);
	GIMME(join);
}
