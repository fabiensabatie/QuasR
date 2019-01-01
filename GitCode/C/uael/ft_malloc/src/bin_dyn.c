/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_dyn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pool.h"

#include <errno.h>
#include <sys/mman.h>

static int	bin_mmap(t_bin **pbin, t_bin **bhd,
	struct s_size_class *cl, size_t sz)
{
	void		*mem;
	t_bin		*bin;
	uint16_t	tail;

	sz = cl ? (cl->page_size * (cl->nb_pages + 1))
		: (sz + sizeof(t_bin) + (2 * sizeof(t_chunk)) - 1) & -sizeof(t_chunk);
	mem = mmap(NULL, sz, PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (mem == MAP_FAILED)
		return (-errno);
	*pbin = mem;
	bin = *pbin;
	*bin = (t_bin){ .bhd = bhd, .size = sz };
	bin->head = (t_chunk *)((t_bin *)mem + 1);
	if (!cl)
		*bin->head = (t_chunk){ .lrg = 1, .rfc = 1 };
	else
	{
		tail = (uint16_t)(((bin->size - sizeof(t_bin)) / sizeof(t_chunk)) - 1);
		bin->tail = bin->head + tail;
		*bin->tail = (t_chunk){ .off = tail, .rfc = 1 };
		*bin->head = (t_chunk){ .nxt = tail };
	}
	return (0);
}

void		*bin_dyalloc(t_bin **p, struct s_size_class *cl, size_t s, size_t a)
{
	void	*ptr;
	t_bin	*prev;
	t_bin	**bhd;

	bhd = p;
	prev = NULL;
	while (1)
		if (!*p)
		{
			if (bin_mmap(p, bhd, cl, s))
				return (NULL);
			(*p)->prev = prev;
			return (!cl ? (*p)->head + 1 : bin_alloc(*p, s, a));
		}
		else if (cl && (ptr = bin_alloc(*p, s, a)))
			return (ptr);
		else
		{
			prev = *p;
			p = &(*p)->next;
		}
}

void		bin_dyfree(t_bin *bin)
{
	if (bin->prev)
		bin->prev->next = bin->next;
	if (bin->next)
		bin->next->prev = bin->prev;
	if (bin == *bin->bhd)
		*bin->bhd = bin->next;
	munmap(bin, bin->size);
}

void		bin_dyfreeall(t_bin *bin)
{
	t_bin *next;

	if (!bin)
		return ;
	next = bin->next;
	bin_dyfree(bin);
	return (bin_dyfreeall(next));
}

void		bin_free(t_bin *bin, t_chunk *chk)
{
	t_chunk	*prv;
	t_chunk	*nxt;

	if (!chk->rfc || --chk->rfc)
		return ;
	if (!chk->lrg)
	{
		prv = chunk_prv(chk, bin);
		nxt = chunk_nxt(chk, bin);
		if ((prv != chk && !prv->rfc) || !nxt->rfc)
		{
			if (!nxt->rfc)
				nxt = chunk_nxt(nxt, bin);
			if (!prv->rfc)
				chk = prv;
			chk->nxt = nxt->off;
			nxt->prv = chk->off;
		}
	}
	if (bin->bhd && chk->lrg)
		bin_dyfree(bin);
}
