/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:10:34 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:49:49 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_abs(long long n)
{
	if (n < 0)
		return ((unsigned long long)-n);
	return ((unsigned long long)n);
}
