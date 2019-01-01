/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:37:19 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:44:53 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/vec.h"

inline t_m4	ft_m4scale(double sx, double sy, double sz)
{
	t_m4	matrix;

	ft_memset(&matrix, '\0', sizeof(t_m4));
	matrix.a[0] = sx;
	matrix.b[1] = sy;
	matrix.c[2] = sz;
	matrix.d[3] = true;
	GIMME(matrix);
}
