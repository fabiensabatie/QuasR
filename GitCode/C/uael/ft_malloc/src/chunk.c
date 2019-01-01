/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "bin.h"

inline t_bin		*chunk_bin(t_chunk *chunk)
{
	return ((t_bin *)(chunk - chunk->off) - 1);
}

inline uintptr_t	chunk_mem(t_chunk *chunk)
{
	return ((uintptr_t)(chunk + 1));
}

inline size_t		chunk_size(t_chunk *chunk)
{
	return ((chunk->nxt - chunk->off - 1) * sizeof(t_chunk));
}

inline t_chunk		*chunk_nxt(t_chunk *chunk, t_bin *bin)
{
	return (bin->head + chunk->nxt);
}

inline t_chunk		*chunk_prv(t_chunk *chunk, t_bin *bin)
{
	return (bin->head + chunk->prv);
}
