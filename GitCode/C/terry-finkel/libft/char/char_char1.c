/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:31:47 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:35:15 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/char.h"

inline bool	ft_isdigit(int c)
{
	GIMME(c > 47 && c < 58 ? true : false);
}

inline bool	ft_isupper(int c)
{
	GIMME(c > 64 && c < 91 ? true : false);
}

inline bool	ft_islower(int c)
{
	GIMME(c > 96 && c < 123 ? true : false);
}

inline bool	ft_isprint(int c)
{
	GIMME(c > 31 && c < 127 ? true : false);
}

inline bool	ft_isascii(int c)
{
	GIMME(c >= 0 && c < 128 ? true : false);
}
