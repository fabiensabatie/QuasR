/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 14:49:47 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 14:49:52 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/list.h"

inline void	ft_lstrem(t_list **alst, t_list *trgt, t_ldtor ldtor, ...)
{
	t_list	*list;
	va_list	ap;

	va_start(ap, ldtor);
	if (*alst == trgt)
	{
		*alst = trgt->next;
		ldtor(trgt->data, trgt->data_size, ap);
	}
	else
	{
		list = *alst;
		while (list->next != trgt)
			list = list->next;
		list->next = trgt->next;
		ldtor(trgt->data, trgt->data_size, ap);
	}
	va_end(ap);
}
