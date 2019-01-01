/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 21:59:10 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:37:44 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io.h"

inline void	ft_putchar(char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
}

inline void	ft_putnbr(int n)
{
	ft_putchar_fd(n, STDOUT_FILENO);
}

inline void	ft_putstr(const char *restrict s)
{
	ft_putstr_fd(s, STDOUT_FILENO);
}

inline void	ft_putendl(const char *s)
{
	ft_putendl_fd(s, STDOUT_FILENO);
}
