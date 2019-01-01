/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:13:59 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/28 16:31:03 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	*ft_vecnew(float x, float y)
{
	t_vec *vec;

	P_ALLOC(vec, t_vec*, sizeof(vec))
	vec->x = x;
	vec->y = y;
	return (vec);
}

t_vec	*ft_getmidcoor(t_vec *a, t_vec *b)
{
	t_vec *mid;

	P_ALLOC(mid, t_vec*, sizeof(mid))
	mid->x = (b->x + a->x) / 2;
	mid->y = (b->y + a->y) / 2;
	return (mid);
}

t_vec	*ft_get_perpendicular_vec(t_vec *a, t_bool way)
{
	t_vec *mid;

	P_ALLOC(mid, t_vec*, sizeof(mid))
	if (way)
	{
		mid->x = a->y;
		mid->y = -a->x;
	}
	else
	{
		mid->x = -a->y;
		mid->y = a->x;
	}
	return (mid);
}

void	ft_swapvec(t_vec *a, t_vec *b)
{
	t_vec temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
