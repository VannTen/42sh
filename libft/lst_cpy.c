/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:39:44 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/04 12:15:06 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include <assert.h>
#include <stddef.h>

static t_bool	add(void *add_from, va_list args)
{
	return (NULL != f_lstpush(add_from, va_arg(args, t_lst**)));
}

t_lst			*lst_add_to(t_lst **add_to, t_lst const *add_from)
{
	assert(add_to != NULL);
	if (f_lstiterr_va((t_lst*)add_from, add, add_to))
		return (*add_to);
	else
		return (NULL);
}

static t_bool	is_present_in(void const *content, t_lst const *lst)
{
	while (lst != NULL && content != lst->content)
		lst = lst->next;
	return (lst != NULL);
}

static t_bool	add_if_not_present(void *add_from, va_list arg)
{
	t_lst	**lst;

	lst = va_arg(arg, t_lst**);
	if (!is_present_in(add_from, *lst))
	{
		*(va_arg(arg, t_bool*)) = TRUE;
		return (NULL != f_lstpush(add_from, lst));
	}
	else
		return (TRUE);
}

t_lst			*lst_add_to_filter(
		t_lst **add_to,
		t_lst const *add_from,
		t_bool *something_added)
{
	assert(add_to != NULL);
	if (f_lstiterr_va((t_lst*)add_from,
				add_if_not_present, add_to, something_added))
		return (*add_to);
	else
		return (NULL);
}
