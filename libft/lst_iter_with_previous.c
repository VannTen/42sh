/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iter_with_previous.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:15:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/23 11:34:35 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include "custom_stddef.h"

static void		*inner_loop(
		t_lst *start,
		t_lst *current,
		void *(*iter)(void *i, void const *j))
{
	void	*error_report;

	error_report = NULL;
	while (start != current && error_report == NULL)
	{
		error_report = iter(current->content, start->content);
		start = start->next;
	}
	return (error_report);
}

static t_bool	map_it(
		t_lst *lst,
		void *(*map)(void *i),
		t_destroy destroy)
{
	t_lst	*new_link;
	void	*new_content;

	new_content = map(lst->content);
	if (new_content != NULL)
	{
		new_link = f_lstnew(new_content);
		if (new_link == NULL)
		{
			destroy(&new_content);
			return (FALSE);
		}
		else
		{
			new_link->next = lst->next;
			lst->next = new_link;
			lst = new_link;
		}
	}
	return (TRUE);
}

t_lst			*f_lst_mapinc_with_previous(
		t_lst *lst,
		void *(*iter)(void *i, void const *j),
		void *(*map)(void *i),
		t_destroy destroy)
{
	t_lst	*i;

	i = lst;
	while (i != NULL)
	{
		inner_loop(lst, i, iter);
		if (!map_it(i, map, destroy))
			break ;
		i = i->next;
	}
	return (i);
}
