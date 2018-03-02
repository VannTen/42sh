/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fifo_lstrelay.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:19:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/24 12:26:49 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo_defs.h"
#include "lst_interface.h"

size_t		f_fifomax(t_fifo *fifo, size_t (*get_max)(const void*))
{
	return (f_lstmax(fifo->begin_lst, get_max));
}

int			f_fifosum_content(t_fifo *fifo,
		int (*add)(const void*))
{
	return (f_lstsum_content(fifo->begin_lst, add));
}

void const	*f_fifo_first_elem(const t_fifo *fifo)
{
	return (f_lst_first_elem(fifo->begin_lst));
}

void		f_fifoiterarray(void *array, t_fifo *fifo,
		void (*apply)(void *lst_content, void *array))
{
	f_lstiterarray(array, fifo->begin_lst, apply);
}

size_t		f_fifoarray_end_early(void *array, t_fifo *fifo,
		size_t size, t_bool (*fifo_on_array)(const void *content, void *array))
{
	return (f_lstarray_end_early(array, fifo->begin_lst, size, fifo_on_array));
}
