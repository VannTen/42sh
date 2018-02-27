/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iter_on_itself.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:01:56 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/28 15:40:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include <stdarg.h>

static void	advance_link(t_lst **lst, t_lst *new_link)
{
	new_link->next = (*lst)->next;
	(*lst)->next = new_link;
	*lst = new_link->next;
}

t_bool		f_lst_insert_on_itself_va(
		t_lst *lst,
		void *(*insert)(void *content, t_lst const *itself, va_list),
		void (*destroy)(void **content),
		...)
{
	va_list	args;
	t_bool	result;

	va_start(args, destroy);
	result = f_lst_insert_on_itself_vas(lst, insert, destroy, args);
	va_end(args);
	return (result);
}

t_bool		f_lst_insert_on_itself_vas(
		t_lst *lst,
		void *(*insert)(void *content, t_lst const *itself, va_list),
		void (*destroy)(void **content),
		va_list args)
{
	va_list	copy;
	void	*insert_content;
	t_lst	*insert_link;
	t_lst	*cur;

	cur = lst;
	while (cur != NULL)
	{
		va_copy(copy, args);
		insert_content = insert(cur->content, lst, copy);
		va_end(copy);
		if (insert_content != NULL)
		{
			insert_link = f_lstnew(insert_content);
			if (insert_link == NULL)
			{
				destroy(&insert_content);
				break ;
			}
			advance_link(&cur, insert_link);
		}
		else
			cur = cur->next;
	}
	return (cur == NULL);
}
