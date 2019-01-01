/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:59:46 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:50:44 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne un maillon “frais”. Les champs content
** et content_size du nouveau maillon sont initialisés par copie des
** paramètres de la fonction. Si le paramètre content est nul, le champs
** content est initialisé à NULL et le champs content_size est initialisé
** à 0 quelque soit la valeur du paramètre content_size. Le champ next
** est initialisé à NULL. Si l’allocation échoue, la fonction renvoie NULL.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	if (!(newlist = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(newlist->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(newlist->content, (void*)content, content_size);
		newlist->content_size = content_size;
	}
	else
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	newlist->next = NULL;
	return (newlist);
}
