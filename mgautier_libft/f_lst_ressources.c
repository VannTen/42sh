/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lst_ressources.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:36:16 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/06 17:52:03 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include "custom_stddef.h"
#include <stdlib.h>

t_lst	*f_lstnew(void const *content)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (new != NULL)
	{
		new->content = (void*)content;
		new->next = NULL;
	}
	return (new);
}

void	f_lstdelone(t_lst *alst, t_destroy del)
{
	if (alst != NULL && del != NULL)
	{
		del(&alst->content);
		alst->content = NULL;
		free(alst);
	}
}

void	f_lstdel(t_lst **alst, t_destroy del)
{
	t_lst	*list;
	t_lst	*to_del;

	list = *alst;
	if (list != NULL && del != NULL)
	{
		while (list != NULL)
		{
			to_del = list;
			list = list->next;
			f_lstdelone(to_del, del);
		}
		*alst = NULL;
	}
}

void	f_lstdel_set(
		t_lst **lst,
		void (*set_del)(void **set, void (*)(void**)),
		void (*del)(void**))
{
	t_lst	*list;
	t_lst	*to_del_link;

	list = *lst;
	while (list != NULL)
	{
		to_del_link = list;
		set_del(&list->content, del);
		list = to_del_link->next;
		to_del_link->next = NULL;
		free(to_del_link);
	}
	*lst = NULL;
}
