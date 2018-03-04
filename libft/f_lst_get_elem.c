/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lst_get_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:27:03 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/04 11:40:25 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"

void		*f_lstsearch(const t_lst *list, const int ref,
		int (*match)(const void *elem))
{
	while (list != NULL)
	{
		if (ref == match(list->content))
			return (list->content);
		list = list->next;
	}
	return (NULL);
}

void const	*f_lst_first_elem(const t_lst *lst)
{
	return (get_lst_elem(lst, 0));
}

t_lst		*advance_list(const t_lst *lst, size_t n_time)
{
	while (n_time != 0 && lst != NULL)
	{
		lst = lst->next;
		n_time--;
	}
	return ((t_lst*)lst);
}

t_lst		*lst_last_link(t_lst *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

void const	*get_lst_elem(const t_lst *lst, size_t index)
{
	lst = advance_list(lst, index);
	return (lst != NULL ? lst->content : NULL);
}
