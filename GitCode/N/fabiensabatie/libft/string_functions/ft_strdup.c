/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:54:26 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:53:00 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(char *src)
{
	int		string_length;
	char	*cpy;

	if (!src)
		return (ft_strdup(""));
	string_length = ft_strlen(src);
	if (!(cpy = (char*)malloc(string_length + 1)))
		return (NULL);
	while (*src)
		*cpy++ = *src++;
	*cpy = '\0';
	return (cpy - string_length);
}
