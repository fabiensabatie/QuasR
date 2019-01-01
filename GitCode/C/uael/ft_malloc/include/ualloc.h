/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ualloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UALLOC_H
# define UALLOC_H

# include <stddef.h>
# include <stdint.h>

/*
** Memory pool handle definition.
** Pool contains memory chunk and are stack or heap based.
*/
typedef struct s_pool	*t_upool;

struct					s_size_class
{
	size_t				page_size;
	size_t				nb_pages;
	size_t				min_size;
};

struct					s_uconf
{
	struct s_size_class	tiny;
	struct s_size_class	small;
};

extern t_upool			g_uscope;

/*
** Create a new stack memory pool.
** @param mem [in,out] Begin of the stack memory buffer
** @param sz      [in] Size of `mem` stack memory buffer
** @param pool   [out] Pointer to a new pool handle
** @return             0 on success, -1 with errno set otherwise
*/
extern int				ustack(void *mem, size_t sz, t_upool *pool);

/*
** Create a new heap memory pool.
** Heap pool are (un)mapped from file.
** @param pool   [out] Pointer to a new pool handle
** @return             0 on success, -1 with errno set otherwise
*/
extern int				uheap(t_upool *pool, const struct s_uconf *conf);

/*
** Release a memory pool.
** Once released, consider the pool content has fully freed.
** @param pool    [in] Memory pool to release
** @return             0 on success, -1 with errno set otherwise
*/
extern int				urelease(t_upool pool);

/*
** Push a memory pool as the current allocation context.
** Consider using pop to revert to the previous context, as many time
** as you push.
** @param pool    [in] Memory pool to push
** @return             0 on success, -1 with errno set otherwise
*/
extern int				upush(t_upool pool);

/*
** Pop a memory pool and revert to the previous context.
** The last call of `upop` will result on a pool release (eq. `urelease`).
** @return             0 on success, -1 with errno set otherwise
*/
extern int				upop(void);

/*
** Allocate `sz` new memory.
** No zeroed memory guaranty, consider using `uzalloc` or `ucalloc` otherwise.
** @param pool    [in] Memory pool to use (`g_uscope` if `NULL`)
** @param sz      [in] Allocation size in bytes
** @return             Begin of the new memory on success, `NULL` otherwise
*/
extern void				*ualloc(t_upool pool, size_t sz);

/*
** Allocate `sz` new zeroed memory
** @param pool    [in] Memory pool to use (`g_uscope` if `NULL`)
** @param sz      [in] Allocation size in bytes
** @return             Begin of the new memory on success, `NULL` otherwise
*/
extern void				*uzalloc(t_upool pool, size_t sz);

/*
** Allocate zeroed memory with `num` elements of `sz` size
** @param pool    [in] Memory pool to use (`g_uscope` if `NULL`)
** @param num     [in] Number of element to allocate
** @param sz      [in] Allocation size in bytes of an element
** @return             Begin of the new memory on success, `NULL` otherwise
*/
extern void				*ucalloc(t_upool pool, size_t num, size_t sz);

/*
** Re-allocate `ptr` memory pointer to `sz`.
** No zeroed memory guaranty, consider using `uzrealloc` otherwise.
** @param pool    [in] Memory pool to use (`g_uscope` if `NULL`)
** @param ptr     [in] Memory pointer to re-allocate
** @param sz      [in] Re-allocation size in bytes
** @return             Begin of the new memory on success, `NULL` otherwise
*/
extern void				*urealloc(t_upool pool, void *ptr, size_t sz);

/*
** Re-allocate `ptr` memory pointer to `sz` zeroed memory.
** @param pool    [in] Memory pool to use (`g_uscope` if `NULL`)
** @param p       [in] Memory pointer to re-allocate
** @param num     [in] Number of element to allocate
** @param sz      [in] Re-allocation size in bytes
** @return             Begin of the new memory on success, `NULL` otherwise
*/
extern void				*ucrealloc(t_upool pool, void *p, size_t n, size_t sz);

/*
** Re-allocate `ptr` memory pointer to `sz` zeroed memory.
** @param pool    [in] Memory pool to use (`g_uscope` if `NULL`)
** @param ptr     [in] Memory pointer to re-allocate
** @param sz      [in] Re-allocation size in bytes
** @return             Begin of the new memory on success, `NULL` otherwise
*/
extern void				*uzrealloc(t_upool pool, void *ptr, size_t sz);

/*
** Reference a memory pointer, once referenced 'n' time, `ufree` have to be
** called 'n+1' times to release the memory.
** @param pool    [in] Memory pool to use (`g_uscope` if `NULL`)
** @param ptr     [in] Memory pointer to reference
** @return             0 on success, -1 with errno set otherwise
*/
extern int				uref(t_upool pool, void *ptr);

/*
** Un-reference a memory pointer.
** @param pool    [in] Memory pool to use (`g_uscope` if `NULL`)
** @param ptr     [in] Memory pointer to un-reference
*/
extern void				ufree(t_upool pool, void *ptr);

/*
** Retrieve the memory pointer size.
** @param pool    [in] Memory pool to use (`g_uscope` if `NULL`)
** @param ptr     [in] Memory pointer
** @return             Pointer total size
*/
extern size_t			usize(t_upool pool, void *ptr);

/*
** Dump a memory pool to stdout
** @param pool    [in] Memory pool to use (`g_uscope` if `NULL`)
*/
extern void				udump(t_upool pool);

#endif
