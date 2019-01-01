/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:21:20 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:07:54 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mat.h"
#include "libft/vary.h"

inline size_t	ft_dstrgrow(t_dstr *dstr, size_t size)
{
	if ((size += dstr->len + 1) < DSTR_MIN_SIZE
		&& DSTR_MIN_SIZE > dstr->capacity)
		GIMME(ft_dstrctor(dstr, DSTR_MIN_SIZE));
	else if (size > dstr->capacity)
		GIMME(ft_dstrctor(dstr, IS_POW2(size) ? size : ft_stnxpow2(size)));
	GIMME(dstr->capacity);
}

inline size_t	ft_varygrow(t_vary *vary, size_t size)
{
	if ((size += vary->len + 1) < VARY_MIN_SIZE
		&& VARY_MIN_SIZE > vary->capacity)
		GIMME(ft_varyctor(vary, VARY_MIN_SIZE));
	else if (size > vary->capacity)
		GIMME(ft_varyctor(vary, IS_POW2(size) ? size : ft_stnxpow2(size)));
	GIMME(vary->capacity);
}
