/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:56:55 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:08:54 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/vec.h"

inline t_v3	**ft_v3center(t_v3 **avec, size_t size, const t_p2 pos)
{
	double	new_x;
	double	new_y;
	size_t	k;

	new_x = pos.x - (size % 2 ? avec[size / 2]->x
		: (avec[size / 2]->x + avec[size / 2 - 1]->x) / 2);
	new_y = pos.y - (size % 2 ? avec[size / 2]->y
		: (avec[size / 2]->y + avec[size / 2 - 1]->y) / 2);
	k = -1;
	while (++k < size)
	{
		avec[k]->x += new_x;
		avec[k]->y += new_y;
	}
	GIMME(avec);
}

inline t_v4	**ft_v4center(t_v4 **avec, size_t size, const t_p2 pos)
{
	double	new_x;
	double	new_y;
	size_t	k;

	new_x = pos.x - (size % 2 ? avec[size / 2]->x
		: (avec[size / 2]->x + avec[size / 2 - 1]->x) / 2);
	new_y = pos.y - (size % 2 ? avec[size / 2]->y
		: (avec[size / 2]->y + avec[size / 2 - 1]->y) / 2);
	k = -1;
	while (++k < size)
	{
		avec[k]->x += new_x;
		avec[k]->y += new_y;
	}
	GIMME(avec);
}
