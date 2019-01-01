/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:14:01 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:54:10 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	char *last;

	last = NULL;
	while (*str)
		if (*str++ == c)
			last = str - 1;
	if (!c)
		return (str);
	return (last);
}
