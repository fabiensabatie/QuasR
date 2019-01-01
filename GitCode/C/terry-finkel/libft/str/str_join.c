/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 19:10:02 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:31:47 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline char	*ft_strjoin(char *restrict s1, const char *restrict s2,
			bool free)
{
	char	*join;
	size_t	len_s2;

	len_s2 = ft_strlen(s2);
	join = ft_strctor(ft_strlen(s1) + len_s2);
	join = ft_strcpy(join, s1);
	join = ft_strncat(join, s2, len_s2);
	if (free == true)
		ft_strdtor((char **)&s1);
	GIMME(join);
}
