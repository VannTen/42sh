/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:40:08 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/15 11:41:36 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo_defs.h"
#include <stddef.h>

size_t	fifo_len(t_fifo const *fifo)
{
	return (f_lst_len(fifo->begin_lst));
}
