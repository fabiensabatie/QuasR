/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:24:23 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:52:37 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_retsplit(char *str, char c, int n)
{
	char **tab;
	char *ret;
	int i;

	i = 0;
	tab = ft_strsplit(str, c);
	ret = ft_strdup(tab[n]);
	while (tab[i])
		free(tab[i++]);
	free(tab);
	free(ret);
	return (ret);
}


