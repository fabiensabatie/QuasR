/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncpush.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:21:03 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/21 21:50:23 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/vary.h"

inline char	*ft_dstrncpush(t_dstr *dstr, const char *data, size_t size)
{
	GIMME(ft_memmove(ft_dstrnpush(dstr, size), data, size * sizeof(char)));
}
