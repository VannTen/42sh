/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lst_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:01:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/27 15:52:17 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include "bool_interface.h"
#include <stdarg.h>
#include <stdlib.h>

/*
** Check every link of a list with a given test function.
** If all links pass the test, the function returns NULL.
** Otherwise, it returns the adress of the first link that does not pass the
** test.
**
** If any of the arguments is NULL, the function returns NULL : a non existent
** test is true for any link, and a non existent list can't fail the test.
*/

void	*f_lst_every_valid(t_lst const *list,
		t_bool (*test)(const void *content))
{
	if (test == NULL)
		return (NULL);
	while (list != NULL)
	{
		if (test(list->content) == FALSE)
			return (list->content);
		else
			list = list->next;
	}
	return (NULL);
}

void	*f_lst_every_valid_va(
		t_lst const *list,
		t_bool valid_result,
		t_bool (*test)(const void *content, va_list args),
		...)
{
	va_list	args;
	void	*result;

	va_start(args, test);
	result = f_lst_every_valid_vas(list, valid_result, test, args);
	va_end(args);
	return (result);
}

void	*f_lst_every_valid_vas(
		t_lst const *list,
		t_bool valid_result,
		t_bool (*test)(const void *content, va_list args),
		va_list args)
{
	va_list	args_loc;
	t_bool	result;

	if (test == NULL)
		return (NULL);
	while (list != NULL)
	{
		va_copy(args_loc, args);
		result = valid_result ?
			test(list->content, args_loc) : !test(list->content, args_loc);
		va_end(args_loc);
		if (!result)
			return (list->content);
		else
			list = list->next;
	}
	return (NULL);
}
