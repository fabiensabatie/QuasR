/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:10:15 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/06 16:10:16 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char *first;
	unsigned char *second;

	first = (unsigned char*)s1;
	second = (unsigned char*)s2;
	while (*first == *second && *first && *second)
	{
		first++;
		second++;
	}
	return (*first - *second);
}
