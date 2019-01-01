/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:50:05 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 14:50:18 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/list.h"

inline void	ft_deqpop(t_deque *deque, t_dqtor dqtor, ...)
{
	t_dlist	*tmp;
	va_list	ap;

	va_start(ap, dqtor);
	tmp = deque->head;
	deque->head = tmp->next;
	if (deque->head)
		deque->head->prev = NULL;
	else
		deque->tail = NULL;
	dqtor(tmp->data, tmp->data_size, ap);
	va_end(ap);
	free(tmp);
	tmp = NULL;
}
