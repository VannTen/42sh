/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lst_variadic_err.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:58:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/25 12:35:12 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include "bool_interface.h"
#include <stdarg.h>

t_bool	f_lstiterr_vas(t_lst *lst,
		t_bool (*iter)(void *elem, va_list),
		va_list args)
{
	va_list	copy;
	t_bool	result;

	while (lst != NULL)
	{
		va_copy(copy, args);
		result = iter(lst->content, copy);
		va_end(copy);
		if (!result)
			return (FALSE);
		lst = lst->next;
	}
	return (TRUE);
}

t_bool	f_lstiterr_va(t_lst *lst,
		t_bool (*iter)(void *elem, va_list),
		...)
{
	va_list	args;
	t_bool	result;

	va_start(args, iter);
	result = f_lstiterr_vas(lst, iter, args);
	va_end(args);
	return (result);
}

t_bool	f_lstiterr_vas_const(t_lst const *lst,
		t_bool (*iter)(void const *elem, va_list),
		va_list args)
{
	va_list	copy;
	t_bool	result;

	while (lst != NULL)
	{
		va_copy(copy, args);
		result = iter(lst->content, copy);
		va_end(copy);
		if (!result)
			return (FALSE);
		lst = lst->next;
	}
	return (TRUE);
}

t_bool	f_lstiterr_va_const(t_lst const *lst,
		t_bool (*iter)(void const *elem, va_list),
		...)
{
	va_list	args;
	t_bool	result;

	va_start(args, iter);
	result = f_lstiterr_vas_const(lst, iter, args);
	va_end(args);
	return (result);
}
