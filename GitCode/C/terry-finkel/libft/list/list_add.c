/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 21:27:00 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:40:25 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/list.h"

inline void	ft_lstadd(t_list **alst, t_list *newlink)
{
	newlink->next = *alst;
	*alst = newlink;
}

inline void	ft_dlstadd(t_dlist **adlst, t_dlist *newlink)
{
	if (*adlst)
		(*adlst)->prev = newlink;
	newlink->next = *adlst;
	*adlst = newlink;
}

inline void	ft_deqadd(t_deque *deque, t_dlist *newlink)
{
	if (deque->head)
		deque->head->prev = newlink;
	else
		deque->tail = newlink;
	newlink->next = deque->head;
	deque->head = newlink;
}
