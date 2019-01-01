/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:39:25 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:01:17 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/vec.h"

inline t_p2	*ft_p2ctor(const int x, const int y)
{
	t_p2	*point;

	point = (t_p2 *)ft_malloc(sizeof(t_p2));
	point->x = x;
	point->y = y;
	GIMME(point);
}

inline t_v3	*ft_v3ctor(const double x, const double y, const double z)
{
	t_v3	*vec;

	vec = (t_v3 *)ft_malloc(sizeof(t_v3));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	GIMME(vec);
}

inline t_v4	*ft_v4ctor(const double x, const double y, const double z,
				const bool w)
{
	t_v4	*vec;

	vec = (t_v4 *)ft_malloc(sizeof(t_v4));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	vec->w = w;
	GIMME(vec);
}
