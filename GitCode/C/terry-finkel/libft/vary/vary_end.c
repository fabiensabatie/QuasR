/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:21:15 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/21 21:49:47 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vary.h"

inline char	*ft_dstrend(t_dstr *dstr)
{
	GIMME(dstr->buff + dstr->len);
}

inline void	*ft_varyend(t_vary *vary)
{
	GIMME((char *)vary->buff + (vary->data_size * vary->len));
}
