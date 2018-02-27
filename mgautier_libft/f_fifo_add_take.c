/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fifo_add_take.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:12:14 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/30 18:04:36 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo_defs.h"

t_fifo	*f_fifo_add(t_fifo *fifo, const void *content)
{
	t_lst	*new_end;

	if (fifo == NULL)
		return (NULL);
	new_end = f_add_end_lst(fifo->end_lst, content);
	if (new_end == NULL)
		return (NULL);
	else
		fifo->end_lst = new_end;
	if (fifo->begin_lst == NULL)
		fifo->begin_lst = fifo->end_lst;
	return (fifo);
}

void	*f_fifo_take(t_fifo *fifo)
{
	void	*content;

	if (fifo == NULL || fifo->begin_lst == NULL)
		return (NULL);
	content = f_lstpop(&(fifo->begin_lst));
	if (fifo->begin_lst == NULL)
		fifo->end_lst = NULL;
	return (content);
}
