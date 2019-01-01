/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:09:39 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/10 13:09:40 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parcourt la liste lst en appliquant à chaque maillon la fonction
** f et crée une nouvelle liste “fraiche” avec malloc(3) résultant
** des applications successives. Si une allocation échoue, la fonction
** renvoie NULL.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*lst_start;
	t_list	*last;

	current = NULL;
	lst_start = NULL;
	last = NULL;
	if (lst)
	{
		lst_start = f(lst);
		last = lst_start;
		lst = lst->next;
		while (lst->next)
		{
			current = f(lst);
			last->next = current;
			last = current;
			lst = lst->next;
		}
		current = f(lst);
		last->next = current;
	}
	return (lst_start);
}
