/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:05:53 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:05:59 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mlxh.h"

inline void	ftx_showimg(t_mlx *mlx, const int x, const int y)
{
	(void)mlx_put_image_to_window(_MLX_ID, _MLX_WIN_ID, _MLX_IMG_ID, x, y);
}
