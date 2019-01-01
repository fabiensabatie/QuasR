/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_clr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:27:52 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:27:58 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline void	ft_strclr(char *s)
{
	int		k;
	size_t	len;

	k = -1;
	len = ft_strlen(s);
	while ((unsigned int)++k < len)
		*(s + k) = '\0';
}
