/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:16:11 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:37:21 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io.h"
#include "libft/mem.h"
#include "libft/str.h"
#include "libft/vary.h"

#define BUFF_SIZE (4096)

inline int	get_next_line(int const fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	char			*end;
	ssize_t			nb;
	static t_dstr	dstr[USHRT_MAX];

	end = NULL;
	while ((!dstr[fd].len || (end || !(end = ft_strchr(dstr[fd].buff, '\n')))))
		if (!(nb = ft_read(fd, buff, BUFF_SIZE)))
			NOMOAR;
		else if (!(end = ft_dstrncpush(dstr + fd, buff, (size_t)nb)))
			ONOES;
		else if ((end = ft_strchr(end, '\n')))
			NOMOAR;
	if (!(nb = end ? (end - dstr[fd].buff + 1) : (ssize_t)dstr[fd].len))
		KTHXBYE;
	*line = ft_malloc((size_t)(nb + (end ? 1 : 0)) * sizeof(char));
	(*line)[ft_dstrncpy(*line, dstr + fd, (size_t)nb) - (end ? 1 : 0)] = '\0';
	GIMME(1);
}
