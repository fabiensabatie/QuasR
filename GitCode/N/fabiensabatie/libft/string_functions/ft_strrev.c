/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:06:42 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/09 19:06:58 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	void	swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char			*ft_strrev(char *str)
{
	int i;
	int y;
	int size;

	i = 0;
	y = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	size = i;
	while (i > (size / 2))
	{
		i--;
		swap(&str[y], &str[i]);
		y++;
	}
	return (str);
}
