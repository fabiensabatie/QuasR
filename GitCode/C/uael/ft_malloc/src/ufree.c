/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ufree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pool.h"

#include <errno.h>

int			uref(t_pool *pool, void *ptr)
{
	t_chunk	*chk;
	t_bin	*bin;
	int		ret;

	if (!ptr || (size_t)ptr % sizeof(t_chunk))
		return (0);
	if (!pool)
		pool = g_uscope;
	ret = -1;
	pthread_mutex_lock(&pool->lock);
	if ((chk = bin_lookup(pool, ptr, &bin)) && chk->rfc)
	{
		++chk->rfc;
		ret = 0;
	}
	pthread_mutex_unlock(&pool->lock);
	return (ret);
}

void		ufree(t_pool *pool, void *ptr)
{
	t_chunk	*chk;
	t_bin	*bin;

	if (!ptr || (size_t)ptr % sizeof(t_chunk))
		return ;
	if (!pool)
		pool = g_uscope;
	pthread_mutex_lock(&pool->lock);
	if ((chk = bin_lookup(pool, ptr, &bin)))
		bin_free(bin, chk);
	pthread_mutex_unlock(&pool->lock);
}

size_t		usize(t_pool *pool, void *ptr)
{
	t_chunk	*chk;
	t_bin	*bin;
	size_t	ret;

	if (!ptr || (size_t)ptr % sizeof(t_chunk))
		return (0);
	if (!pool)
		pool = g_uscope;
	ret = 0;
	pthread_mutex_lock(&pool->lock);
	if ((chk = bin_lookup(pool, ptr, &bin)))
		ret = chk->lrg
			? bin->size - sizeof(t_bin) - sizeof(t_chunk)
			: chunk_size(chk);
	pthread_mutex_unlock(&pool->lock);
	return (ret);
}
