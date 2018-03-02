/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fifo_ressources.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:04:37 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 15:46:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo_defs.h"
#include "lst_interface.h"
#include <stdlib.h>

void	f_fifo_destroy(t_fifo **to_destroy, t_destroy del)
{
	t_fifo	*fifo;

	fifo = *to_destroy;
	if (fifo != NULL && del != NULL)
	{
		f_lstdel(&fifo->begin_lst, del);
		fifo->end_lst = NULL;
	}
	free(fifo);
	*to_destroy = NULL;
}

t_fifo	*f_fifo_create(void)
{
	t_fifo	*new;

	new = malloc(sizeof(t_fifo));
	if (new != NULL)
	{
		new->begin_lst = NULL;
		new->end_lst = NULL;
	}
	return (new);
}

t_lst	*f_fifo_extract(t_fifo **fifo)
{
	t_lst	*extract;

	if (*fifo == NULL)
		return (NULL);
	extract = (*fifo)->begin_lst;
	(*fifo)->begin_lst = NULL;
	(*fifo)->end_lst = NULL;
	free(*fifo);
	*fifo = NULL;
	return (extract);
}
