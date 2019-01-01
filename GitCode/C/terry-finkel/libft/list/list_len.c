/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 21:46:09 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:41:27 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/list.h"

inline size_t	ft_lstlen(const t_list *list)
{
	size_t	size;

	size = 0;
	while (list)
	{
		list = list->next;
		++size;
	}
	GIMME(size);
}
