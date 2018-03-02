/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_are_equivalent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:01:46 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/05 20:06:46 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include "bool_interface.h"
#include "misc_interface.h"
#include <stdarg.h>

t_bool	content_is_equ(void const *content2, va_list arg)
{
	t_bool		(*equ)(void const*, void const*);
	void const	*content_equ;

	content_equ = va_arg(arg, void const*);
	equ = va_arg(arg, t_bool (*)(void const*, void const*));
	return (equ(content_equ, content2));
}

t_bool	content_has_equ(void const *content, va_list arg)
{
	t_lst	**lst2;
	t_bool	(*equ)(void const*, void const*);

	lst2 = va_arg(arg, t_lst**);
	equ = va_arg(arg, t_bool (*)(void const*, void const*));
	return (NULL !=
			f_lsttakeone_if_va(lst2, TRUE, content_is_equ, content, equ));
}

void	*copy_ref(void const *elem)
{
	return ((void*)elem);
}

t_bool	lst_same_contents(t_lst const *lst1, t_lst const *lst2,
		t_bool (*equ)(void const*, void const*))
{
	t_lst	*copy_lst2;
	t_bool	result;

	copy_lst2 = f_lstmap(lst2, copy_ref, no_destroy);
	if (copy_lst2 != NULL)
		result =
			NULL == f_lst_every_valid_va(lst1, TRUE,
					content_has_equ, &copy_lst2, equ)
			&& copy_lst2 == NULL;

	else
		result = FALSE;
	f_lstdel(&copy_lst2, no_destroy);
	return (result);
}
