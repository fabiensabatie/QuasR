/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:11:40 by nfinkel           #+#    #+#             */
/*   Updated: 2018/05/08 13:14:07 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vec.h"

inline t_v3	*ft_v3norm(t_v3 *vec)
{
	double	magnitude;

	magnitude = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	vec->x = vec->x / magnitude;
	vec->y = vec->y / magnitude;
	vec->z = vec->z / magnitude;
	GIMME(vec);
}

inline t_v4	*ft_v4norm(t_v4 *vec)
{
	double	magnitude;

	magnitude = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
	vec->x = vec->x / magnitude;
	vec->y = vec->y / magnitude;
	vec->z = vec->z / magnitude;
	GIMME(vec);
}
