/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_take_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:30:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/04 13:36:57 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include <stdlib.h>
#include <stdarg.h>

void	*f_lsttakeone_if_vas(
		t_lst **lst,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		va_list args)
{
	va_list	args_loc;
	t_lst	**current;
	void	*to_take;
	t_lst	*to_del;
	t_bool	result;

	current = lst;
	to_take = NULL;
	while (*current != NULL)
	{
		va_copy(args_loc, args);
		result = match((*current)->content, args_loc);
		va_end(args_loc);
		if (truth == result)
		{
			to_take = (*current)->content;
			to_del = *current;
			*current = (*current)->next;
			free(to_del);
			break ;
		}
		else
			current = &(*current)->next;
	}
	return (to_take);
}

void	*f_lsttakeone_if_va(
		t_lst **lst,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		...)
{
	va_list	args_loc;
	void	*to_take;

	va_start(args_loc, match);
	to_take = f_lsttakeone_if_vas(lst, truth, match, args_loc);
	va_end(args_loc);
	return (to_take);
}

t_lst	*f_split_lst_vas(
		t_lst **lst,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		va_list args)
{
	va_list	args_loc;
	t_lst	**current;
	t_lst	**ptr_new_lst;
	t_lst	*new_list;

	current = lst;
	ptr_new_lst = &new_list;
	while (*current != NULL)
	{
		va_copy(args_loc, args);
		if (truth == match((*current)->content, args_loc))
		{
			*ptr_new_lst = *current;
			*current = (*current)->next;
			ptr_new_lst = &((*ptr_new_lst)->next);
		}
		else
			current = &(*current)->next;
		va_end(args_loc);
	}
	(*ptr_new_lst) = NULL;
	return (new_list);
}

t_lst	*f_split_lst_va(
		t_lst **lst,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		...)
{
	va_list	args_loc;
	t_lst	*new_lst;

	va_start(args_loc, match);
	new_lst = f_split_lst_vas(lst, truth, match, args_loc);
	va_end(args_loc);
	return (new_lst);
}
