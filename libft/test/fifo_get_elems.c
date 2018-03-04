/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_get_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:43:39 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/04 12:15:54 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo_interface.h"
#include "convert_data_struct_interface.h"
#include "useful_macros.h"
#include "misc_interface.h"
#include <stdlib.h>

static t_bool	test(void)
{
	t_fifo		*fifo;
	char const	str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	size_t		index;

	fifo = str_to_fifo(str);
	index = ARRAY_LENGTH(str) - 1;
	if (fifo != NULL)
	{
		if (NULL == get_fifo_elem(fifo, index))
		{
			index--;
			while (index != 0
					&& *(char const*)get_fifo_elem(fifo, index)
					== str[index])
				index--;
		}
	}
	f_fifo_destroy(&fifo, no_destroy);
	return (index == 0);
}

int				main(void)
{
	return (test() ?
			EXIT_SUCCESS : EXIT_FAILURE);
}
