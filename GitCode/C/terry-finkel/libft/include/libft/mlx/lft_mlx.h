/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_mlx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:58:00 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:09:15 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_MLX_H
# define LFT_MLX_H

# include "libft/vec.h"
# include "libft/vary.h"
# include "libft/mlx/keys.h"

# define _MLX_ID mlx->mlx
# define _MLX_IMG mlx->img[mlx->cur_img]
# define _MLX_IMG_ID mlx->img[mlx->cur_img]->img
# define _MLX_WIN_ID mlx->win[mlx->cur_win]
# define _DATA_MLX_ID(x) (x)->mlx->mlx
# define _DATA_MLX_IMG(x) (x)->mlx->img[(x)->mlx->cur_img]
# define _DATA_MLX_IMG_ID(x) (x)->mlx->img[(x)->mlx->cur_img]->img
# define _DATA_MLX_WIN_ID(x) (x)->mlx->win[(x)->mlx->cur_win]

typedef struct		s_mlx_img
{
	char			*addr;
	int				bppx;
	int				endian;
	int				sl;
	int				height;
	int				width;
	void			*img;
}					t_mlx_img;

typedef struct		s_mlx
{
	t_mlx_img		**img;
	uint16_t		cur_img;
	uint16_t		cur_win;
	void			*mlx;
	void			**win;
}					t_mlx;

extern t_mlx_img	*ftx_blurimg(t_mlx_img *img);
extern t_mlx_img	*ftx_buffpixel(t_mlx_img *img, const int x, const int y,
					int color);
extern t_mlx_img	*ftx_clearimg(t_mlx_img *img);
extern void			ftx_clearwin(t_mlx *mlx, const uint16_t index);
extern t_mlx_img	*ftx_clipimg(t_mlx_img *img, const t_p2 begin,
					const t_p2 end);
extern t_mlx_img	*ftx_drawline(t_mlx_img *img, const t_v4 v1,
					const t_v4 v2, int color);
extern t_mlx_img	*ftx_hline(t_mlx_img *img, const t_v4 v1,
					const t_v4 v2, int color);
extern t_mlx_img	*ftx_imgctor(t_mlx *mlx, const int width,
					const int height);
extern void			ftx_imgdtor(void *data, va_list ap);
extern t_mlx		*ftx_mlxctor(t_mlx *mlx);
extern void			ftx_mlxdtor(t_mlx *mlx);
extern t_mlx_img	*ftx_setimg(t_mlx *mlx, const uint16_t n);
extern void			*ftx_setwin(t_mlx *mlx, const uint16_t n);
extern void			ftx_showimg(t_mlx *mlx, const int x, const int y);
extern t_mlx_img	*ftx_vline(t_mlx_img *img, const t_v4 v1,
					const t_v4 v2, int color);
extern void			ftx_winctor(t_mlx *mlx, char *title, const int size_x,
					const int size_y);
extern void			ftx_windtor(void *data, va_list ap);

/*
** MLX functions
*/
extern int			mlx_clear_window(void *mlx_ptr, void *win_ptr);
extern int			mlx_destroy_image(void *mlx_ptr, void *img_ptr);
extern int			mlx_destroy_window(void *mlx_ptr, void *win_ptr);
extern char			*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
					int *size_line, int *endian);
extern void			*mlx_new_image(void *mlx_ptr, int width, int height);
extern void			*mlx_new_window(void *mlx_ptr, int size_x, int size_y,
					char *title);
extern int			mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
					void *img_ptr, int x, int y);
extern void			*mlx_init(void);

#endif
