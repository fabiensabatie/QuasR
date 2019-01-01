/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdint.h>
# include <stddef.h>

extern void	free(void *ptr);
extern void *memalign(size_t alignment, size_t size);
extern void	*malloc(size_t size);
extern void	*realloc(void *ptr, size_t size);
extern void	*reallocf(void *ptr, size_t size);
extern void	*calloc(size_t nmemb, size_t size);
extern void	show_alloc_mem(void);

#endif
