/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:08:34 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:41:58 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mat.h"

inline int32_t	ft_32npow(const intmax_t nb, uint8_t power)
{
	int32_t	sum;

	if (!power)
		YAY;
	sum = nb;
	while (--power)
		sum *= nb;
	GIMME(sum);
}

inline int64_t	ft_64npow(const intmax_t nb, uint8_t power)
{
	int64_t	sum;

	if (!power)
		YAY;
	sum = nb;
	while (--power)
		sum *= nb;
	GIMME(sum);
}

inline size_t	ft_stnpow(const intmax_t nb, uint8_t power)
{
	size_t	sum;

	if (!power)
		YAY;
	sum = nb;
	while (--power)
		sum *= nb;
	GIMME(sum);
}
