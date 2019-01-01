/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_clip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:07:18 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:07:30 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mlxh.h"

inline t_mlx_img	*ftx_clipimg(t_mlx_img *img, const t_p2 begin,
					const t_p2 end)
{
	int	x;
	int	y;

	y = begin.y - 1;
	while (++y <= end.y)
	{
		x = begin.x - 1;
		while (++x <= end.x)
			ftx_buffpixel(img, x, y, 0x00000000);
	}
	GIMME(img);
}
