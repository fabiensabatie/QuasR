/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 21:44:56 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 14:47:47 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/list.h"

inline t_list	*ft_lstnode(const t_list *list, size_t n)
{
	while (n-- > 0)
	{
		list = list->next;
		if (!list)
			ZOMG;
	}
	GIMME((t_list *)list);
}
