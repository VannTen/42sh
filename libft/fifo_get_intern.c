/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_get_intern.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:48:11 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/09 17:48:55 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo_defs.h"
#include "lst_interface.h"

t_lst const	*get_intern_lst(t_fifo const *fifo)
{
	return (fifo->begin_lst);
}
