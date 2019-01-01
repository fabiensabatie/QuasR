/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:05:11 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:13:47 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mlxh.h"

inline t_mlx_img	*ftx_setimg(t_mlx *mlx, const uint16_t n)
{
	mlx->cur_img = n;
	GIMME(_MLX_IMG);
}

inline void			*ftx_setwin(t_mlx *mlx, const uint16_t n)
{
	mlx->cur_win = n;
	GIMME(_MLX_WIN_ID);
}
