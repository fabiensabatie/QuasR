/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_zpow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:14:33 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 15:14:35 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mat.h"

inline double	ft_zpowi(t_complex z, uint8_t n)
{
	double		tmp;
	t_complex	zp;

	zp.i = z.i;
	zp.r = z.r;
	while (--n)
	{
		tmp = zp.r;
		if (n > 1)
			zp.r = z.r * zp.r - z.i * zp.i;
		zp.i = z.r * zp.i + tmp * z.i;
	}
	GIMME(zp.i);
}

inline double	ft_zpowr(t_complex z, uint8_t n)
{
	double		tmp;
	t_complex	zp;

	zp.i = z.i;
	zp.r = z.r;
	while (--n)
	{
		tmp = zp.r;
		zp.r = z.r * zp.r - z.i * zp.i;
		if (n > 1)
			zp.i = z.r * zp.i + tmp * z.i;
	}
	GIMME(zp.r);
}
