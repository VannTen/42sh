/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_several.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:38:39 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/20 14:41:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo_defs.h"
#include "lst_interface.h"
#include <assert.h>

t_bool	fifo_are_equ(t_fifo const *fifo_1, t_fifo const *fifo_2,
		t_bool (*is_equ)(void const*, void const*))
{
	return (lst_equ(fifo_1->begin_lst, fifo_2->begin_lst, is_equ));
}

t_fifo	*join_fifo(t_fifo *fifo_1, t_fifo *fifo_2)
{
	t_lst	*new_end;
	t_lst	*new_begin;

	assert(fifo_1 != NULL && fifo_2 != NULL);
	new_end = fifo_2->end_lst;
	new_begin = join_lst(fifo_1->end_lst, f_fifo_extract(&fifo_2));
	fifo_1->end_lst = new_end;
	if (fifo_1->begin_lst == NULL)
		fifo_1->begin_lst = new_begin;
	return (fifo_1);
}

t_fifo	*add_lst_to_fifo(t_fifo *fifo, t_lst *lst)
{
	join_lst(fifo->end_lst, lst);
	if (lst != NULL)
		fifo->end_lst = lst_last_link(lst);
	if (fifo->begin_lst == NULL)
		fifo->begin_lst = lst;
	return (fifo);
}
