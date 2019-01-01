/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:21:29 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/21 21:51:07 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vary.h"

inline char	*ft_dstrpush(t_dstr *dstr)
{
	GIMME(ft_dstrnpush(dstr, 1));
}

inline void	*ft_varypush(t_vary *vary)
{
	GIMME(ft_varynpush(vary, 1));
}
