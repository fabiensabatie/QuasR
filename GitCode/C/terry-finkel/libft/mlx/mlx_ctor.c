/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:04:45 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:13:33 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/hdl.h"
#include "libft/mem.h"
#include "libft/mlxh.h"

t_vary	g_mlx_img_vary_null = {NULL, 0, 0, sizeof(t_mlx_img *)};
t_vary	g_mlx_win_vary_null = {NULL, 0, 0, sizeof(void *)};
t_vary	*g_mlx_img_vary = &g_mlx_img_vary_null;
t_vary	*g_mlx_win_vary = &g_mlx_win_vary_null;

inline t_mlx_img	*ftx_imgctor(t_mlx *mlx, const int width, const int height)
{
	t_mlx_img	*img;

	img = (t_mlx_img *)ft_memalloc(sizeof(t_mlx_img));
	if (!(img->img = mlx_new_image(mlx->mlx, width, height)))
		ft_errhdl(NULL, 0, 0, ERR_MLXIMG);
	img->height = height;
	img->width = width;
	img->addr = mlx_get_data_addr(img->img, &img->bppx, &img->sl, &img->endian);
	*(t_mlx_img **)ft_varypush(g_mlx_img_vary) = img;
	mlx->img = g_mlx_img_vary->buff;
	GIMME(img);
}

inline t_mlx		*ftx_mlxctor(t_mlx *mlx)
{
	ft_memset(mlx, '\0', sizeof(t_mlx));
	if (!(_MLX_ID = mlx_init()))
		ft_errhdl(NULL, 0, 0, ERR_MLX);
	GIMME(mlx);
}

inline void			ftx_winctor(t_mlx *mlx, char *title, const int size_x,
					const int size_y)
{
	void	*win;

	if (!(win = mlx_new_window(_MLX_ID, size_x, size_y, title)))
		ft_errhdl(NULL, 0, 0, ERR_MLXWIN);
	*(void **)ft_varypush(g_mlx_win_vary) = win;
	mlx->win = g_mlx_win_vary->buff;
}
