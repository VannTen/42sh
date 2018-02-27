/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_take_elems.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:59:18 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/04 14:22:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo_defs.h"
#include "lst_interface.h"

void	*f_fifotakeone_if_vas(
		t_fifo *fifo,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		va_list args)
{
	void		*content;
	void const	*cmp_content;

	cmp_content = get_lst_elem(fifo->end_lst, 0);
	content = f_lsttakeone_if_vas(&fifo->begin_lst, truth, match, args);
	if (content == cmp_content)
		fifo->end_lst = lst_last_link(fifo->begin_lst);
	return (content);
}

void	*f_fifotakeone_if_va(
		t_fifo *fifo,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		...)
{
	va_list	args_loc;
	void	*to_take;

	va_start(args_loc, match);
	to_take = f_fifotakeone_if_vas(fifo, truth, match, args_loc);
	va_end(args_loc);
	return (to_take);
}

t_fifo	*f_split_fifo_vas(
		t_fifo *fifo,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		va_list args)
{
	t_lst	*new_list;
	t_fifo	*new_fifo;

	new_list = f_split_lst_vas(&fifo->begin_lst, truth, match, args);
	if (new_list != NULL)
	{
		new_fifo = f_fifo_create();
		if (new_fifo != NULL)
		{
			new_fifo->begin_lst = new_list;
			new_fifo->end_lst = lst_last_link(new_list);
		}
		else
			fifo->begin_lst = join_lst(fifo->begin_lst, new_list);
	}
	else
		new_fifo = NULL;
	return (new_fifo);
}

t_fifo	*f_split_fifo_va(
		t_fifo *fifo,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		...)
{
	va_list	args_loc;
	t_fifo	*new_fifo;

	va_start(args_loc, match);
	new_fifo = f_split_fifo_vas(fifo, truth, match, args_loc);
	va_end(args_loc);
	return (new_fifo);
}
