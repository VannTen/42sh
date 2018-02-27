/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lst_insert_remove_end.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:20:33 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/16 17:53:04 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include <stdlib.h>

static t_lst	*end_list(t_lst *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void			*f_pushend_lst(t_lst **lst, void *content)
{
	t_lst	*new_link;

	new_link = f_lstnew(content);
	if (new_link != NULL)
	{
		if (*lst == NULL)
			*lst = new_link;
		else
			end_list(*lst)->next = new_link;
		return (NULL);
	}
	else
		return (content);
}

static t_lst	*one_before_last(t_lst *lst)
{
	if (lst != NULL)
	{
		if (lst->next != NULL)
		{
			while (lst->next->next != NULL)
				lst = lst->next;
		}
		else
			lst = NULL;
	}
	return (lst);
}

void			*f_popend_lst(t_lst **lst)
{
	t_lst		*ante_last;
	void		*ret_content;
	t_lst		*last;

	if (*lst == NULL)
		return (NULL);
	ante_last = one_before_last(*lst);
	if (ante_last == NULL)
	{
		last = *lst;
		*lst = NULL;
	}
	else
	{
		last = ante_last->next;
		ante_last->next = NULL;
	}
	ret_content = last->content;
	last->content = NULL;
	free(last);
	return (ret_content);
}
