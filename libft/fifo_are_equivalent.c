/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_are_equivalent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:03:47 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/20 19:11:53 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo_defs.h"
#include "lst_interface.h"
#include "bool_interface.h"

t_bool	fifo_same_contents(
		t_fifo const *fifo1,
		t_fifo const *fifo2,
		t_bool (*equ)(void const*, void const*))
{
	return (lst_same_contents(fifo1->begin_lst, fifo2->begin_lst, equ));
}
