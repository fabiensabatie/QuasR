/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ualloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pool.h"

#include <errno.h>
#include <libft.h>

int			pool_lazy_init(t_pool *pool)
{
	int				ret;
	int				psz;
	struct s_uconf	*cf;

	if (pool->def.heap.conf.tiny.page_size
		&& pool->def.heap.conf.small.page_size)
		return (0);
	ret = 0;
	if ((psz = getpagesize()) < 0)
		ret = psz;
	else
	{
		cf = &pool->def.heap.conf;
		!cf->tiny.page_size ? (cf->tiny.page_size = (size_t)psz) : 0;
		!cf->tiny.nb_pages ? (cf->tiny.nb_pages = 1) : 0;
		if (!cf->tiny.min_size)
			cf->tiny.min_size = (cf->tiny.page_size * cf->tiny.nb_pages) / 4;
		!cf->small.page_size ? (cf->small.page_size = (size_t)psz) : 0;
		!cf->small.nb_pages ? (cf->small.nb_pages = 4) : 0;
		if (!cf->small.min_size)
			cf->small.min_size = (cf->small.page_size * cf->small.nb_pages) / 4;
	}
	return (ret);
}

void		*unlocked_ualloc(t_pool *pool, size_t sz, size_t al)
{
	void *ptr;

	if ((al % ALIGN) != 0)
	{
		errno = EINVAL;
		return (NULL);
	}
	sz = (sz + ALIGN - 1) & -ALIGN;
	if (pool->kind == POOL_STACK)
		return (bin_alloc(pool->def.stack.bin, sz, al));
	pool_lazy_init(pool);
	if (sz < pool->def.heap.conf.tiny.min_size)
		ptr = bin_dyalloc(&pool->def.heap.bins_tiny,
			&pool->def.heap.conf.tiny, sz, al);
	else if (sz < pool->def.heap.conf.small.min_size)
		ptr = bin_dyalloc(&pool->def.heap.bins_small,
			&pool->def.heap.conf.small, sz, al);
	else
		ptr = bin_dyalloc(&pool->def.heap.bins_large, NULL, sz, al);
	return (ptr);
}

void		*ualloc(t_pool *pool, size_t sz)
{
	void *ptr;

	if (!sz)
		return (NULL);
	if (!pool)
		pool = g_uscope;
	else if (pool->kind == POOL_NONE)
	{
		errno = EINVAL;
		return (NULL);
	}
	pthread_mutex_lock(&pool->lock);
	ptr = unlocked_ualloc(pool, sz, ALIGN);
	pthread_mutex_unlock(&pool->lock);
	return (ptr);
}

void		*uzalloc(t_pool *pool, size_t sz)
{
	void *ptr;

	if ((ptr = ualloc(pool, sz)))
		ft_memset(ptr, 0, sz);
	return (ptr);
}

void		*ucalloc(t_pool *pool, size_t num, size_t sz)
{
	return (uzalloc(pool, num * sz));
}
