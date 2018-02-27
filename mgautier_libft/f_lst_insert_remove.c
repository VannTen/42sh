/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lst_insert_remove.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:41:09 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/11 17:02:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include <stdlib.h>

t_lst	*f_add_end_lst(t_lst *last_link, const void *content)
{
	t_lst	*new_last_link;

	new_last_link = f_lstnew(content);
	if (last_link != NULL)
		last_link->next = new_last_link;
	return (new_last_link);
}

t_lst	*f_add_end_lst_2(t_lst **last_link, const void *content)
{
	t_lst	*new_last_link;

	new_last_link = f_lstnew(content);
	if (*last_link != NULL)
		(*last_link)->next = new_last_link;
	*last_link = new_last_link;
	return (new_last_link);
}

t_lst	*f_lstpush(void const *content, t_lst **list)
{
	t_lst	*new;

	new = f_lstnew(content);
	if (new == NULL)
		return (NULL);
	new->next = *list;
	*list = new;
	return (new);
}

void	*f_lstpop(t_lst **first_link)
{
	t_lst	*pop;
	void	*content;

	pop = *first_link;
	if (pop != NULL)
	{
		*first_link = (*first_link)->next;
		content = pop->content;
		free(pop);
	}
	else
		content = NULL;
	return (content);
}

t_bool	f_lstremoveif_one(t_lst **lst, int ref, int (*match)(const void *elem),
		t_destroy content_dtor)
{
	t_lst	*to_del;
	t_lst	*loc_lst;

	if (ref == match((*lst)->content))
	{
		to_del = *lst;
		*lst = (*lst)->next;
		f_lstdelone(to_del, content_dtor);
		return (TRUE);
	}
	loc_lst = *lst;
	while (loc_lst->next != NULL)
	{
		if (ref == match(loc_lst->next->content))
		{
			to_del = loc_lst->next;
			loc_lst->next = to_del->next;
			f_lstdelone(to_del, content_dtor);
			return (TRUE);
		}
		loc_lst = loc_lst->next;
	}
	return (FALSE);
}
