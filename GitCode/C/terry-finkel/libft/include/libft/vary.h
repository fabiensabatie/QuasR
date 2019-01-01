/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vary.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 08:58:27 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/21 22:34:49 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARY_H
# define VARY_H

# include "hdl.h"

# define DSTR_MIN_SIZE (64)
# define VARY_MIN_SIZE (32)

typedef struct	s_dstr
{
	char		*buff;
	size_t		capacity;
	size_t		len;
}				t_dstr;

typedef struct	s_vary
{
	void		*buff;
	size_t		capacity;
	size_t		len;
	size_t		data_size;
}				t_vary;

extern char		*ft_dstrbegin(t_dstr *dstr);
extern void		ft_dstrclr(t_dstr **adstr);
extern size_t	ft_dstrctor(t_dstr *dstr, size_t size);
extern void		ft_dstrdtor(t_dstr **adstr);
extern char		*ft_dstrend(t_dstr *dstr);
extern size_t	ft_dstrgrow(t_dstr *dstr, size_t size);
extern size_t	ft_dstrncpy(char *dst, t_dstr *dstr, size_t size);
extern char		*ft_dstrncpush(t_dstr *dstr, const char *data, size_t size);
extern char		*ft_dstrnpush(t_dstr *dstr, size_t size);
extern char		*ft_dstrpush(t_dstr *dstr);

extern void		*ft_varybegin(t_vary *vary);
extern void		ft_varyclr(t_vary *vary, t_vdtor vdtor, ...);
extern size_t	ft_varyctor(t_vary *vary, size_t size);
extern void		ft_varydtor(t_vary **avar, t_vdtor vdtor, ...);
extern void		*ft_varyend(t_vary *vary);
extern size_t	ft_varygrow(t_vary *vary, size_t size);
extern void		*ft_varynpush(t_vary *vary, size_t size);
extern void		*ft_varypush(t_vary *vary);

#endif
