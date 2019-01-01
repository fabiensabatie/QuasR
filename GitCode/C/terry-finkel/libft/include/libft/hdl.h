/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:39:06 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/21 21:03:22 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HDL_H
# define HDL_H

# include <errno.h>
# include <string.h>
# include "dependencies.h"

# define ERRMAX (ERR_NO)

typedef enum	e_err
{
	ERR_MLX,
	ERR_MLXIMG,
	ERR_MLXWIN,
	ERR_NO
}				t_err;

typedef void	(*t_dqtor)(void *, size_t, va_list ap);
typedef void	(*t_ldtor)(void *, size_t, va_list ap);
typedef void	(*t_vdtor)(void *, va_list ap);
typedef void	(*t_vdstor)(void *, va_list ap);

NEV				ft_errhdl(void **aptr, size_t size, int err_no, t_err err_code);

#endif
