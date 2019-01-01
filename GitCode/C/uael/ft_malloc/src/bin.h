/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIN_H
# define BIN_H

# include <pthread.h>

# include "ualloc.h"
# include "chunk.h"

typedef struct		s_bin
{
	struct s_bin	**bhd;
	struct s_bin	*prev;
	struct s_bin	*next;
	t_chunk			*head;
	t_chunk			*tail;
	size_t			size;
}					t_bin;

void				*bin_dyalloc(t_bin **pbin, struct s_size_class *class,
						size_t sz, size_t align);
void				bin_dyfree(t_bin *bin);
void				bin_dyfreeall(t_bin *bin);
void				*bin_alloc(t_bin *bin, size_t sz, size_t align);
void				bin_free(t_bin *bin, t_chunk *chk);
int					bin_resize(t_bin *bin, t_chunk *chk, size_t nsz);
t_chunk				*bin_lookup(t_upool pool, void *ptr, t_bin **pbin);

#endif
