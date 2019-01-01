/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_blur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:07:44 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:07:49 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mlxh.h"

inline t_mlx_img	*ftx_blurimg(t_mlx_img *img)
{
	int	x;
	int	y;

	y = -1;
	while (++y < img->height && (x = -1))
		while (++x < img->width)
			ftx_buffpixel(img, x, y, 0xA0000000);
	GIMME(img);
}
