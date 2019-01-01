/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "pool.h"

void	free(void *ptr)
{
	ufree(NULL, ptr);
}

void	*memalign(size_t alignment, size_t size)
{
	void *ptr;

	pthread_mutex_lock(&g_uscope->lock);
	ptr = unlocked_ualloc(g_uscope, size, alignment);
	pthread_mutex_unlock(&g_uscope->lock);
	return (ptr);
}

void	*malloc(size_t sz)
{
	return (ualloc(NULL, sz));
}

void	*realloc(void *ptr, size_t sz)
{
	return (urealloc(NULL, ptr, sz));
}

void	*reallocf(void *ptr, size_t sz)
{
	void *tmp;

	tmp = realloc(ptr, sz);
	if (tmp)
		return (tmp);
	free(ptr);
	return (NULL);
}
