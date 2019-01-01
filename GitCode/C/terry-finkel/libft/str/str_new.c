/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:33:06 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:37:47 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/str.h"

inline char	*ft_strctor(size_t size)
{
	GIMME((char *)ft_memalloc(sizeof(char) * (size + 1)));
}
