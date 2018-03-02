/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_while.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:11:07 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/19 11:11:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include <stdarg.h>

t_bool	lst_do_while_err_va(
		t_lst *lst,
		t_bool (*loop_body)(void *, va_list),
		t_bool (*loop_condition)(void const*, va_list),
		...)
{
	va_list	args;
	t_bool	result;

	va_start(args, loop_condition);
	result = lst_do_while_err_vas(lst, loop_body, loop_condition, args);
	va_end(args);
	return (result);
}

t_bool	lst_do_while_err_vas(
		t_lst *lst,
		t_bool (*loop_body)(void *, va_list),
		t_bool (*loop_condition)(void const*, va_list),
		va_list args)
{
	va_list	copy[2];
	t_bool	continue_loop;

	while (lst != NULL)
	{
		va_copy(copy[0], args);
		if (!loop_body(lst->content, copy[0]))
			return (FALSE);
		va_end(copy[0]);
		va_copy(copy[1], args);
		continue_loop = loop_condition(lst->content, copy[1]);
		va_end(copy[1]);
		if (!continue_loop)
			break ;
		lst = lst->next;
	}
	return (TRUE);
}
