/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:14:29 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:14:53 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/mlxh.h"

inline t_mlx_img	*ftx_buffpixel(t_mlx_img *img, const int x, const int y,
					int color)
{
	char	*pos;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		GIMME(img);
	pos = img->addr + (y * img->sl) + (x * img->bppx / 8);
	if (img->endian)
		color = ft_bswap(color);
	ft_memmove(pos, &color, sizeof(color));
	GIMME(img);
}
