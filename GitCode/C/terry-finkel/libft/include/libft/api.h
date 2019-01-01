/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:39:08 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/21 21:12:34 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef API_H
# define API_H

# include "dependencies.h"

extern char	*ft_ctime(const time_t *clock);
extern char	*ft_getenv(const char *name);

#endif
