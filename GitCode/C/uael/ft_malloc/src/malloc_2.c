/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "pool.h"

#include <libft/io.h>

void			*calloc(size_t nb, size_t sz)
{
	return (ucalloc(NULL, nb, sz));
}

static size_t	dump(t_pool *pool, t_bin *bin, t_chunk *chunk, int i)
{
	size_t c;

	if (i == 0)
	{
		chunk = bin->head;
		if (pool->kind != POOL_STACK)
			ft_printf("         (%10u) |%p -> %p|\n",
				bin->size, bin, bin + bin->size);
	}
	c = usize(pool, (void *)chunk_mem(chunk));
	ft_printf("%.3d: [%c] (%10u) |%p -> %p|\n",
		i, chunk->rfc ? 'X' : ' ', c, chunk_mem(chunk), bin->head + chunk->nxt);
	if (!chunk->rfc)
		c = 0;
	if (chunk->lrg || chunk->nxt == bin->tail->off)
		return (bin->next ? c + dump(pool, bin->next, bin->next->head, 0) : c);
	return (c + dump(pool, bin, bin->head + chunk->nxt, i + 1));
}

void			udump(t_pool *pool)
{
	size_t c;

	c = 0;
	if (pool->kind == POOL_STACK)
	{
		ft_printf("-- ALL -------------------------------------------------\n");
		if (pool->def.stack.bin && pool->def.stack.bin->head)
			c += dump(pool, pool->def.stack.bin, NULL, 0);
	}
	else
	{
		ft_printf("-- TINY ------------------------------------------------\n");
		if (pool->def.heap.bins_tiny && pool->def.heap.bins_tiny->head)
			c += dump(pool, pool->def.heap.bins_tiny, NULL, 0);
		ft_printf("-- SMALL -----------------------------------------------\n");
		if (pool->def.heap.bins_small && pool->def.heap.bins_small->head)
			c += dump(pool, pool->def.heap.bins_small, NULL, 0);
		ft_printf("-- LARGE -----------------------------------------------\n");
		if (pool->def.heap.bins_large && pool->def.heap.bins_large->head)
			c += dump(pool, pool->def.heap.bins_large, NULL, 0);
	}
	ft_printf("-- TOTAL (%10zu) ----------------------------------\n", c);
}

void			show_alloc_mem(void)
{
	udump(g_uscope);
}
