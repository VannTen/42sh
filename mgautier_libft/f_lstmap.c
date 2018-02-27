/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:00:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/18 19:36:25 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include "custom_stddef.h"
#include <stdlib.h>
#include <stdarg.h>

/*
** function to produce with a given list another one, using the function given
** as parameters
**
** The destiny of the original parameter lst is left to change : it can produce
** a copy, modify it, and destroy (or not) the original list.
** The allocation has to be done by change.
*/

t_lst	*f_lstmap(
		t_lst const *lst,
		void *(*change)(void const*),
		t_destroy destroy)
{
	t_lst	**new_lst;
	t_lst	*final_list;
	void	*new_content;

	new_lst = &final_list;
	final_list = NULL;
	while (lst != NULL)
	{
		new_content = change(lst->content);
		*new_lst = f_lstnew(new_content);
		if ((*new_lst) == NULL || (*new_lst)->content == NULL)
		{
			f_lstdel(&final_list, destroy);
			break ;
		}
		new_lst = &(*new_lst)->next;
		lst = lst->next;
	}
	return (final_list);
}

t_lst	*f_lstmap_vas(
		t_lst const *lst,
		void *(*change)(void const*, va_list args),
		t_destroy destroy,
		va_list args)
{
	t_lst	**new_lst;
	t_lst	*final_list;
	void	*new_content;
	va_list	args_loc;

	new_lst = &final_list;
	final_list = NULL;
	while (lst != NULL)
	{
		va_copy(args_loc, args);
		new_content = change(lst->content, args_loc);
		va_end(args_loc);
		*new_lst = f_lstnew(new_content);
		if ((*new_lst) == NULL || (*new_lst)->content == NULL)
		{
			f_lstdel(&final_list, destroy);
			break ;
		}
		new_lst = &(*new_lst)->next;
		lst = lst->next;
	}
	return (final_list);
}

t_lst	*f_lstmap_va(
		t_lst const *lst,
		void *(*change)(void const*, va_list args),
		t_destroy destroy,
		...)
{
	t_lst	*new_lst;
	va_list	args;

	va_start(args, destroy);
	new_lst = f_lstmap_vas(lst, change, destroy, args);
	va_end(args);
	return (new_lst);
}

t_lst	*f_lstmapi(
		t_lst const *lst,
		void *(*change)(void const *elem, unsigned int index),
		t_destroy del)
{
	t_lst			**new_lst;
	t_lst			*final_list;
	void			*new_content;
	unsigned int	index;

	new_lst = &final_list;
	index = 0;
	final_list = NULL;
	while (lst != NULL)
	{
		new_content = change(lst->content, index);
		*new_lst = f_lstnew(new_content);
		if ((*new_lst)->next == NULL || (*new_lst)->content == NULL)
		{
			f_lstdel(&final_list, del);
			break ;
		}
		*new_lst = (*new_lst)->next;
		lst = lst->next;
		index++;
	}
	return (final_list);
}
