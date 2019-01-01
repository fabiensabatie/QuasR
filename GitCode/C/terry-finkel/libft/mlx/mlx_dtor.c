/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:47:12 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:12:35 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/mlxh.h"

extern t_vary	*g_mlx_img_vary;
extern t_vary	*g_mlx_win_vary;

inline void	ftx_imgdtor(void *data, va_list ap)
{
	t_mlx	*mlx;

	mlx = va_arg(ap, t_mlx *);
	mlx_destroy_image(mlx->mlx, (*(t_mlx_img **)(data))->img);
	ft_memdtor((void **)&*(t_mlx_img **)data);
}

inline void	ftx_mlxdtor(t_mlx *mlx)
{
	ft_varydtor(&g_mlx_img_vary, ftx_imgdtor, mlx);
	ft_varydtor(&g_mlx_win_vary, ftx_windtor, mlx);
}

inline void	ftx_windtor(void *data, va_list ap)
{
	t_mlx	*mlx;

	mlx = va_arg(ap, t_mlx *);
	mlx_destroy_window(mlx->mlx, *(void **)(data));
}
