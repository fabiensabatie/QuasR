/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:45:51 by nfinkel           #+#    #+#             */
/*   Updated: 2018/05/08 19:45:52 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/hdl.h"
#include "libft/io.h"
#include "libft/str.h"
#include "libft/vary.h"

#define BUFF_SIZE (1024)

static t_dstr	g_dstr_stack = {NULL, 0, 0};
static t_dstr	*g_dstr = &g_dstr_stack;

inline char	*ft_readfile(const char *path)
{
	char	buff[BUFF_SIZE];
	char	*kernel;
	int		fd;
	ssize_t	bytes;

	if (!(fd = open(path, O_RDONLY)))
		ft_errhdl(NULL, 0, errno, ERR_NO);
	while ((bytes = ft_read(fd, buff, BUFF_SIZE)))
		ft_dstrncpush(g_dstr, buff, bytes);
	kernel = ft_strdup(g_dstr->buff);
	ft_dstrdtor(&g_dstr);
	GIMME(kernel);
}
