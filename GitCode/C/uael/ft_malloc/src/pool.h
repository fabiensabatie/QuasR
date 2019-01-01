/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POOL_H
# define POOL_H

# include "bin.h"

# define MAX_POOL   (1 << 8)
# define ALIGN      (sizeof(t_chunk))

enum				e_pool
{
	POOL_NONE = 0,
	POOL_STACK,
	POOL_HEAP,
};

struct				s_stack
{
	t_bin			*bin;
};

struct				s_heap
{
	struct s_uconf	conf;
	t_bin			*bins_tiny;
	t_bin			*bins_small;
	t_bin			*bins_large;
};

union				u_pool
{
	struct s_stack	stack;
	struct s_heap	heap;
};

typedef struct		s_pool
{
	struct s_pool	*prev;
	enum e_pool		kind;
	union u_pool	def;
	pthread_mutex_t	lock;
}					t_pool;

t_pool				g_heap_dft_stack;

int					pool_lazy_init(t_pool *pool);
void				*unlocked_ualloc(t_pool *pool, size_t sz, size_t al);

#endif
