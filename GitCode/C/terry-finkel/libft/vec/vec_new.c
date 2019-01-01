/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:38:08 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 15:38:09 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vec.h"

inline t_p2	ft_p2new(const int x, const int y)
{
	GIMME(((t_p2){.x = x, .y = y}));
}

inline t_v3	ft_v3new(const double x, const double y, const double z)
{
	GIMME(((t_v3){.x = x, .y = y, .z = z}));
}

inline t_v4	ft_v4new(const double x, const double y, const double z,
			const bool w)
{
	GIMME(((t_v4){.x = x, .y = y, .z = z, .w = w}));
}
