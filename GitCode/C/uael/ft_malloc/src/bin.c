/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
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

static void		trim(t_bin *bin, t_chunk *chk, size_t sz)
{
	t_chunk	*nxt;
	t_chunk	*nxt_nxt;

	nxt = (t_chunk *)(chunk_mem(chk) + sz);
	*nxt = (t_chunk){ .nxt = chk->nxt, .prv = chk->off,
		.off = (uint16_t)(nxt - bin->head) };
	nxt_nxt = chunk_nxt(nxt, bin);
	if (!nxt_nxt->rfc)
		chunk_nxt(nxt_nxt, bin)->prv = nxt->off;
	else
		nxt_nxt->prv = nxt->off;
	chk->nxt = nxt->off;
}

void			*bin_alloc(t_bin *bin, size_t sz, size_t align)
{
	t_chunk	*chk;

	chk = bin->head;
	while (chk->rfc || (chunk_size(chk) - (chunk_mem(chk) % align)) < sz)
	{
		if (chk->nxt == bin->tail->off)
			return (NULL);
		chk = chunk_nxt(chk, bin);
	}
	if ((chunk_mem(chk) % align))
	{
		while (chunk_mem(chk) % align)
		{
			++chk;
			++chk->off;
		}
		chunk_nxt(chk, bin)->prv = chk->off;
		chunk_prv(chk, bin)->nxt = chk->off;
	}
	if (chunk_size(chk) >= sz + sizeof(t_chunk))
		trim(bin, chk, sz);
	chk->rfc = 1;
	chk->lrg = 0;
	return ((void *)chunk_mem(chk));
}

int				bin_resize(t_bin *bin, t_chunk *chk, size_t nsz)
{
	t_chunk	*nxt;
	size_t	chsz;
	int		ret;

	if (chk->lrg)
		return (-1);
	ret = 0;
	chsz = chunk_size(chk);
	nsz = (nsz + ALIGN - 1) & -ALIGN;
	if (chsz < nsz)
	{
		nxt = chunk_nxt(chk, bin);
		if (nxt->rfc || (chunk_size(nxt) + sizeof(t_chunk) + chsz) < nsz)
			ret = -1;
		else
		{
			nxt = chunk_nxt(nxt, bin);
			chk->nxt = nxt->off;
			nxt->prv = chk->off;
			chsz = chunk_size(chk);
		}
	}
	if (!ret && chsz > nsz)
		trim(bin, chk, nsz);
	return (ret);
}
