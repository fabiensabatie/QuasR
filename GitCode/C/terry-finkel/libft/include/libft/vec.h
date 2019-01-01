/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:30:12 by nfinkel           #+#    #+#             */
/*   Updated: 2018/05/08 13:16:02 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include <math.h>
# include "dependencies.h"

typedef struct	s_p2
{
	int			x;
	int			y;
}				t_p2;

typedef struct	s_v3
{
	double		x;
	double		y;
	double		z;
}				t_v3;

typedef struct	s_v4
{
	double		x;
	double		y;
	double		z;
	bool		w;
}				t_v4;

typedef struct	s_m4
{
	double		a[4];
	double		b[4];
	double		c[4];
	bool		d[4];
}				t_m4;

extern t_p2		*ft_p2ctor(int x, int y);
extern t_p2		*ft_p2map(t_p2 *point, int x, int y);
extern t_p2		ft_p2new(int x, int y);

extern t_v3		**ft_v3center(t_v3 **av, size_t size, t_p2 pos);
extern t_v3		*ft_v3ctor(double x, double y, double z);
extern t_v3		**ft_v3m4iter(t_v3 **av, t_m4 matrix, size_t size);
extern t_v3		*ft_v3m4mult(t_v3 *vec, t_m4 matrix);
extern t_v3		ft_v3new(double x, double y, double z);
extern t_v3		*ft_v3norm(t_v3 *vec);
extern t_v3		*ft_v3update(t_v3 *vec, double x, double y, double z);

extern t_v4		**ft_v4center(t_v4 **av, size_t size, t_p2 pos);
extern t_v4		*ft_v4ctor(double x, double y, double z, bool w);
extern t_v4		**ft_v4m4iter(t_v4 **av, t_m4 matrix, size_t size);
extern t_v4		*ft_v4m4mult(t_v4 *vec, t_m4 matrix);
extern t_v4		ft_v4new(double x, double y, double z, bool w);
extern t_v4		*ft_v4norm(t_v4 *vec);
extern t_v4		*ft_v4update(t_v4 *vec, double x, double y, double z);

extern t_m4		ft_m4rotx(double theta);
extern t_m4		ft_m4roty(double theta);
extern t_m4		ft_m4rotz(double theta);
extern t_m4		ft_m4scale(double sx, double sy, double sz);
extern t_m4		ft_m4trans(double x, double y, double z);

#endif
