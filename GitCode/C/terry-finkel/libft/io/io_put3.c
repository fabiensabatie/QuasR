/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:38:59 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:38:04 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io.h"
#include "libft/vec.h"

inline void	ft_putm4(const t_m4 matrix)
{
	char	c1;
	char	c2;
	char	c3;
	char	c4;

	c1 = (matrix.d[0] ? '1' : '0');
	c2 = (matrix.d[1] ? '1' : '0');
	c3 = (matrix.d[2] ? '1' : '0');
	c4 = (matrix.d[3] ? '1' : '0');
	ft_printf("4x4 MATRIX (%p)\n[%9f, %9f, %9f, %9f]\n[%9f, %9f, %9f, %9f]\n"\
		"[%9f, %9f, %9f, %9f]\n[%9c, %9c, %9c, %9c]\n", matrix, matrix.a[0],\
		matrix.a[1], matrix.a[2], matrix.a[3], matrix.b[0], matrix.b[1],\
		matrix.b[2], matrix.b[3], matrix.c[0], matrix.c[1], matrix.c[2],\
		matrix.c[3], c1, c2, c3, c4);
}

inline void	ft_putv3(const t_v3 vec)
{
	ft_printf("3x1 VECTOR (%p)\n[%9f]\n[%9f]\n[%9f]\n", &vec, vec.x, vec.y,\
		vec.z);
}

inline void	ft_putv4(const t_v4 vec)
{
	ft_printf("4x1 VECTOR (%p)\n[%9f]\n[%9f]\n[%9f]\n[%9c]\n", &vec, vec.x,\
		vec.y, vec.z, vec.w ? '1' : '0');
}
