/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:17:08 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:50:29 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Prend en paramètre l’adresse d’un pointeur sur un maillon et libère
** la mémoire du contenu de ce maillon avec la fonction del passée en
** paramètre puis libère la mémoire du maillon en lui même avec free(3).
** La mémoire du champ next ne doit en aucun cas être libérée. Pour
** terminer, le pointeur sur le maillon maintenant libéré doit être mis
** à NULL (de manière similaire à la fonction ft_memdel de la partie
** obligatoire).
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst)
	{
		del((*alst)->content, (*alst)->content_size);
		*alst = NULL;
	}
}
