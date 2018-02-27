/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_from_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:35:43 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/11 16:32:42 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include <stdarg.h>

void	*lst_do_from_end(t_lst *lst,
		void *initial_result,
		void *(*iter)(void *content, void *result_on_next))
{
	if (lst == NULL)
		return (initial_result);
	else
		return (iter(lst->content,
					lst_do_from_end(lst->next, initial_result, iter)));
}

void	*lst_do_from_end_va(t_lst *lst,
		void *initial_result,
		void *(*iter)(void *content, void *result_on_next, va_list args),
		...)
{
	va_list	args;
	void	*result;

	va_start(args, iter);
	result = lst_do_from_end_vas(lst, initial_result, iter, args);
	va_end(args);
	return (result);
}

void	*lst_do_from_end_vas(t_lst *lst,
		void *initial_result,
		void *(*iter)(void *content, void *result_on_next, va_list args),
		va_list args)
{
	va_list	copy;
	void	*result;

	if (lst == NULL)
		return (initial_result);
	else
	{
		va_copy(copy, args);
		result = iter(lst->content,
				lst_do_from_end_vas(lst->next, initial_result, iter, args),
				copy);
		va_end(copy);
		return (result);
	}
}
