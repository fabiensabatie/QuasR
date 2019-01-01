/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:22:07 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:15:37 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"

inline void	ft_swap(void *a, void *b, size_t size)
{
	void	*swap;

	swap = ft_malloc(size);
	ft_memmove(swap, a, size);
	ft_memmove(a, b, size);
	ft_memmove(b, swap, size);
	free(swap);
}
