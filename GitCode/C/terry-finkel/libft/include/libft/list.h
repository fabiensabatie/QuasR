/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 21:24:12 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:41:38 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "hdl.h"

typedef struct		s_list
{
	size_t			data_size;
	void			*data;
	struct s_list	*next;
}					t_list;

typedef struct		s_dlist
{
	size_t			data_size;
	void			*data;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct		s_deque
{
	t_dlist			*head;
	t_dlist			*tail;
}					t_deque;

extern void			ft_lstadd(t_list **alst, t_list *newlink);
extern void			ft_lstappend(t_list *list, t_list *newlink);
extern t_list		*ft_lstctor(const void *data, size_t data_size);
extern void			ft_lstdtor(t_list **alst, t_ldtor ldtor, ...);
extern t_list		*ft_lstfdup(t_list *lst, t_list *(*f)(t_list *));
extern void			ft_lstinsert(t_list **alst, t_list *newlink,
					int (*cmp)(void *, void *));
extern void			ft_lstfiter(t_list *lst, void (*f)(t_list *));
extern size_t		ft_lstlen(const t_list *list);
extern t_list		*ft_lstnode(const t_list *list, size_t n);
extern void			ft_lstrem(t_list **alst, t_list *trgt, t_ldtor ldtor, ...);

extern void			ft_dlstadd(t_dlist **adlst, t_dlist *newlink);
extern void			ft_dlstappend(t_dlist *dlist, t_dlist *newlink);
extern t_dlist		*ft_dlstctor(const void *content, size_t content_size);

extern void			ft_deqadd(t_deque *deque, t_dlist *newlink);
extern void			ft_deqappend(t_deque *deque, t_dlist *newlink);
extern void			ft_deqdtor(t_deque **adeq, t_dqtor dqtor, ...);
extern void			ft_deqeject(t_deque *deque, t_dqtor dqtor, ...);
extern void			ft_deqpop(t_deque *deque, t_dqtor dqtor, ...);

#endif
