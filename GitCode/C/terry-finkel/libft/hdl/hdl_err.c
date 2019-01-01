/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 09:57:42 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:35:41 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/hdl.h"
#include "libft/io.h"

static const char	*g_errcode[ERRMAX] =
{
	"could not initialize mlx",
	"could not initialize mlx window",
	"could not initialize mlx image"
};

NIV	ft_errhdl(void **aptr, size_t size, int err_no, t_err err_code)
{
	char	*err_msg;

	(void)aptr;
	(void)size;
	if (err_code == ERR_NO)
	{
		err_msg = strerror(err_no);
		ft_fatal(err_msg, err_no);
	}
	else
		ft_fatal(g_errcode[err_code], err_code);
}
