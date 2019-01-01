/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:45:24 by nfinkel           #+#    #+#             */
/*   Updated: 2018/05/08 13:10:51 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/vec.h"

inline t_v3	*ft_v3m4mult(t_v3 *vec, const t_m4 matrix)
{
	t_v3	tmp;

	tmp.x = matrix.a[0] * vec->x + matrix.a[1] * vec->y + matrix.a[2] * vec->z;
	tmp.y = matrix.b[0] * vec->x + matrix.b[1] * vec->y + matrix.b[2] * vec->z;
	tmp.z = matrix.c[0] * vec->x + matrix.c[1] * vec->y + matrix.c[2] * vec->z;
	ft_memmove(vec, &tmp, sizeof(t_v3));
	GIMME(vec);
}

inline t_v4	*ft_v4m4mult(t_v4 *vec, const t_m4 matrix)
{
	t_v4	tmp;

	tmp.x = (matrix.a[0] * vec->x) + (matrix.a[1] * vec->y);
	tmp.x += (matrix.a[2] * vec->z) + (matrix.a[3] * (vec->w ? 1.0 : 0.0));
	tmp.y = (matrix.b[0] * vec->x) + (matrix.b[1] * vec->y);
	tmp.y += (matrix.b[2] * vec->z) + (matrix.b[3] * (vec->w ? 1.0 : 0.0));
	tmp.z = (matrix.c[0] * vec->x) + (matrix.c[1] * vec->y);
	tmp.z += (matrix.c[2] * vec->z) + (matrix.c[3] * (vec->w ? 1.0 : 0.0));
	tmp.w = (matrix.d[0] * vec->x) + (matrix.d[1] * vec->y);
	tmp.w += (matrix.d[2] * vec->z) + (matrix.d[3] * (vec->w ? 1.0 : 0.0));
	ft_memmove(vec, &tmp, sizeof(t_v4));
	GIMME(vec);
}
