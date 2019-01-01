/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_trans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:37:38 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:44:50 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/vec.h"

inline t_m4	ft_m4trans(double x, double y, double z)
{
	t_m4	matrix;

	ft_memset(&matrix, '\0', sizeof(t_m4));
	matrix.a[0] = 1.0;
	matrix.a[3] = x;
	matrix.b[1] = 1.0;
	matrix.b[3] = y;
	matrix.c[2] = 1.0;
	matrix.c[3] = z;
	matrix.d[3] = true;
	GIMME(matrix);
}
