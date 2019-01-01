/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_eject.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:50:39 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:41:01 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/list.h"

inline void	ft_deqeject(t_deque *deque, t_dqtor dqtor, ...)
{
	t_dlist	*tmp;
	va_list	ap;

	va_start(ap, dqtor);
	tmp = deque->tail;
	deque->tail = tmp->prev;
	if (deque->tail)
		deque->tail->next = NULL;
	else
		deque->head = NULL;
	dqtor(tmp->data, tmp->data_size, ap);
	va_end(ap);
	free(tmp);
	tmp = NULL;
}
