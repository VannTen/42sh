/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_get_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:51:40 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/24 11:59:06 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo_defs.h"
#include "lst_interface.h"

void const	*get_fifo_elem(t_fifo const *fifo, size_t index)
{
	return (get_lst_elem(fifo->begin_lst, index));
}
