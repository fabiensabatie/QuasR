/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 12:18:44 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:15:04 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mlxh.h"

inline t_mlx_img		*ftx_hline(t_mlx_img *img, const t_v4 v1,
						const t_v4 v2, int color)
{
	int	k;
	int	p;

	if (v1.y < 0 || v1.y >= img->height)
		GIMME(img);
	k = (int)MIN(v1.x, v2.x);
	p = (int)MAX(v1.x, v2.x);
	while (++k <= p)
		ftx_buffpixel(img, k, v1.y, color);
	GIMME(img);
}

inline t_mlx_img		*ftx_vline(t_mlx_img *img, const t_v4 v1,
						const t_v4 v2, int color)
{
	int	k;
	int	p;

	if (v1.x < 0 || v1.x >= img->width)
		GIMME(img);
	k = (int)MIN(v1.y, v2.y);
	p = (int)MAX(v1.y, v2.y);
	while (++k <= p)
		ftx_buffpixel(img, v1.x, k, color);
	GIMME(img);
}

static inline t_mlx_img	*p_line(t_mlx_img *img, const t_v4 v1,
						const t_v4 v2, int color)
{
	if (v1.x == v2.x && v1.y == v2.y)
		GIMME(ftx_buffpixel(img, v1.x, v1.y, color));
	else if (v1.x == v2.x)
		GIMME(ftx_vline(img, v1, v2, color));
	else
		GIMME(ftx_hline(img, v1, v2, color));
}

inline t_mlx_img		*ftx_drawline(t_mlx_img *img, const t_v4 v1,
						const t_v4 v2, int color)
{
	int		k;
	int		x;
	int		y;
	double	kx;
	double	ky;

	if ((v1.x < 0 && v2.x < 0) || (v1.x > img->width && v2.x > img->width)
		|| (v1.y < 0 && v2.y < 0) || (v1.y > img->height && v2.y > img->height))
		GIMME(img);
	if (v1.x == v2.x || v1.y == v2.y)
		GIMME(p_line(img, v1, v2, color));
	k = MAX(fabs(v1.x - v2.x), fabs(v1.y - v2.y) + 1);
	kx = (v2.x - v1.x) / k;
	ky = (v2.y - v1.y) / k;
	while (k--)
		if ((x = (int)(v1.x + kx * k)) >= 0 && x <= img->width
			&& (y = (int)(v1.y + ky * k)) >= 0 && y <= img->height)
			ftx_buffpixel(img, x, y, color);
	GIMME(img);
}
