/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:19:29 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/04 14:13:05 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbj.h"

void	ft_dlstdel(t_dlst **elem, void (*del)(void *, size_t))
{
	t_dlst	*lst;

	if (!elem || !*elem || !del)
		return ;
	lst = *elem;
	while (*elem)
	{
		del((*elem)->data, (*elem)->data_size);
		lst = lst->next;
		ft_memdel((void**)elem);
		*elem = lst;
	}
}
