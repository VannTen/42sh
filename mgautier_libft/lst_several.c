/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_several.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:40:28 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/20 16:02:09 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include "misc_interface.h"
#include <stddef.h>

t_lst	*join_lst(t_lst *lst_1, t_lst const *to_join)
{
	t_lst	*join;

	join = (t_lst*)to_join;
	if (lst_1 != NULL)
	{
		if (to_join != NULL)
			lst_last_link(lst_1)->next = join;
		return (lst_1);
	}
	else
		return (join);
}

t_lst	*lst_join(t_lst const *lst_1, t_lst const *lst_2)
{
	t_lst	*copy[2];

	copy[0] = lst_cpy(lst_1);
	copy[1] = lst_cpy(lst_2);
	if ((copy[0] == NULL && lst_1 != NULL)
			|| (copy[1] == NULL && lst_2 != NULL))
	{
		f_lstdel(&copy[0], no_destroy);
		f_lstdel(&copy[1], no_destroy);
		return (NULL);
	}
	else
		return (join_lst(copy[0], copy[1]));
}

t_bool	lst_equ(t_lst const *lst1, t_lst const *lst2,
		t_bool (*equ)(void const*, void const*))
{
	while (lst1 != NULL && lst2 != NULL)
	{
		if (!equ(lst1->content, lst2->content))
			break ;
		lst1 = lst1->next;
		lst2 = lst2->next;
	}
	return (lst1 == NULL && lst2 == NULL);
}

t_bool	lst_equ_to_n(t_lst const *lst1, t_lst const *lst2, size_t index,
		t_bool (*equ)(void const*, void const*))
{
	while (lst1 != NULL && lst2 != NULL && index != 0)
	{
		if (!equ(lst1->content, lst2->content))
			break ;
		lst1 = lst1->next;
		lst2 = lst2->next;
		index--;
	}
	return (index == 0 ||
			(lst1 == NULL && lst2 == NULL));
}
