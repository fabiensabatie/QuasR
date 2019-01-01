/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_lookup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pool.h"

t_chunk			*lookup_one(int lrg, t_bin *bin, uintptr_t ptr, t_bin **pbin)
{
	t_chunk	*chk;

	while (bin)
		if (ptr > ((uintptr_t)bin + bin->size) || ptr < (uintptr_t)bin)
			bin = bin->next;
		else if (lrg)
		{
			*pbin = bin;
			return (bin->head);
		}
		else if ((chk = bin->head))
		{
			while (chunk_mem(chk) < ptr || ptr > (uintptr_t)chunk_nxt(chk, bin))
			{
				if (chk->nxt == bin->tail->off)
					return (NULL);
				chk = chunk_nxt(chk, bin);
			}
			if (!chk->rfc)
				return (NULL);
			*pbin = bin;
			return (chk);
		}
	return (NULL);
}

t_chunk			*bin_lookup(t_pool *pool, void *ptr, t_bin **pbin)
{
	t_chunk *chk;

	if (pool->kind == POOL_STACK)
		return (lookup_one(0, pool->def.stack.bin, (uintptr_t)ptr, pbin));
	if ((chk = lookup_one(0, pool->def.heap.bins_tiny, (uintptr_t)ptr, pbin)))
		return (chk);
	if ((chk = lookup_one(0, pool->def.heap.bins_small, (uintptr_t)ptr, pbin)))
		return (chk);
	return (lookup_one(1, pool->def.heap.bins_large, (uintptr_t)ptr, pbin));
}
