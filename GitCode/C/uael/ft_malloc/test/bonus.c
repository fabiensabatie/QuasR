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

#include "ualloc.h"
#include "../src/pool.h"

#include <assert.h>
#include <string.h>
#include <libft/io.h>
#include <malloc.h>

uint8_t g_mem[UINT32_MAX];

int main(int ac, char *av[])
{
	void *ptrs[64 * 64];
	t_upool pool1, pool2;

	assert(0 == ustack(g_mem, sizeof(g_mem), &pool1));
	assert(0 == uheap(&pool2, NULL));

	assert(0 == upush(pool1));
	{
		ptrs[0] = malloc(32);
		ptrs[1] = malloc(64);
		ft_printf("POOL1:\n");
		show_alloc_mem();
		ft_printf("\n");

		assert(0 == upush(pool2));
		{
			ptrs[2] = malloc(32);
			ptrs[3] = malloc(64);

			ft_printf("POOL2:\n");
			show_alloc_mem();
			ft_printf("\n");

			uref(NULL, ptrs[2]);
			free(ptrs[2]);

			ft_printf("POOL2:\n");
			show_alloc_mem();
			ft_printf("\n");

			free(ptrs[2]);

			ft_printf("POOL2:\n");
			show_alloc_mem();
			ft_printf("\n");
		}
		ft_printf("\n");
		assert(0 == upop());

		ft_printf("POOL1:\n");
		show_alloc_mem();
		ft_printf("\n");
	}
	assert(0 == upop());

	ft_printf("POOL1:\n");
	udump(pool1);
	ft_printf("\n");

	ft_printf("POOL2:\n");
	udump(pool2);
	ft_printf("\n");

	assert(0 == upush(pool1));
	{
		int *inta = NULL;

		inta = ucrealloc(NULL, inta, 5, sizeof(int));
		assert(usize(NULL, inta) == (((5 * sizeof(int)) + 7) & -8));

		for (unsigned i = 0; i < 5; ++i) {
			inta[i] = -i;
			ft_printf("[%u] = %d\n", i, inta[i]);
		}

		inta = ucrealloc(NULL, inta, 3, sizeof(int));
		assert(usize(NULL, inta) == (((3 * sizeof(int)) + 7) & -8));

		for (unsigned i = 0; i < 3; ++i) {
			ft_printf("[%u] = %d\n", i, inta[i]);
		}

		inta = ucrealloc(NULL, inta, 12, sizeof(int));
		assert(usize(NULL, inta) == (((12 * sizeof(int)) + 7) & -8));

		for (unsigned i = 0; i < 12; ++i) {
			if (i >= 3) inta[i] = -i;
			ft_printf("[%u] = %d\n", i, inta[i]);
		}
	}
	assert(0 == upop());

	assert(0 == upush(pool1));
	{
		int *inta = NULL;

		inta = ucrealloc(NULL, inta, 5, sizeof(int));
		assert(usize(NULL, inta) == (((5 * sizeof(int)) + 7) & -8));

		for (unsigned i = 0; i < 5; ++i) {
			inta[i] = -i;
			ft_printf("[%u] = %d\n", i, inta[i]);
		}

		inta = ucrealloc(NULL, inta, 3, sizeof(int));
		assert(usize(NULL, inta) == (((3 * sizeof(int)) + 7) & -8));

		for (unsigned i = 0; i < 3; ++i) {
			ft_printf("[%u] = %d\n", i, inta[i]);
		}

		inta = ucrealloc(NULL, inta, 12, sizeof(int));
		assert(usize(NULL, inta) == (((12 * sizeof(int)) + 7) & -8));

		for (unsigned i = 0; i < 12; ++i) {
			if (i >= 3) inta[i] = -i;
			ft_printf("[%u] = %d\n", i, inta[i]);
		}
	}
	assert(0 == upop());

	assert(0 == upush(pool1));
	{
		int *inta = NULL;

		inta = ucrealloc(NULL, inta, 5, sizeof(int));
		assert(usize(NULL, inta) == (((5 * sizeof(int)) + 7) & -8));

		for (unsigned i = 0; i < 5; ++i) {
			inta[i] = -i;
			ft_printf("[%u] = %d\n", i, inta[i]);
		}

		inta = ucrealloc(NULL, inta, 3, sizeof(int));
		assert(usize(NULL, inta) == (((3 * sizeof(int)) + 7) & -8));

		for (unsigned i = 0; i < 3; ++i) {
			ft_printf("[%u] = %d\n", i, inta[i]);
		}

		inta = ucrealloc(NULL, inta, 12, sizeof(int));
		assert(usize(NULL, inta) == (((12 * sizeof(int)) + 7) & -8));

		for (unsigned i = 0; i < 12; ++i) {
			if (i >= 3) inta[i] = -i;
			ft_printf("[%u] = %d\n", i, inta[i]);
		}
	}
	assert(0 == upop());

	return 0;
}