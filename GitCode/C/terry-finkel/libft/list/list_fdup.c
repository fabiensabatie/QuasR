/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 21:45:50 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:41:05 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/list.h"

inline t_list	*ft_lstfdup(t_list *lst, t_list *(*f)(t_list *))
{
	t_list		*begin;
	t_list		*new;
	t_list		*tmp;

	tmp = f(lst);
	new = ft_lstctor(tmp->data, tmp->data_size);
	begin = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		new->next = ft_lstctor(tmp->data, tmp->data_size);
		lst = lst->next;
		new = new->next;
	}
	GIMME(begin);
}
