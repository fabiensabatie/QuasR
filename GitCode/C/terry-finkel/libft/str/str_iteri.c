/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_iteri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:32:55 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:33:04 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	k;

	k = -1;
	while (*(s + ++k))
		f((unsigned int)k, s + k);
}
