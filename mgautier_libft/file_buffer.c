/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:08:19 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/27 17:41:03 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_buffer_interface.h"
#include "lst_interface.h"
#include "fifo_interface.h"
#include "string_interface.h"
#include "get_next_elem_interface.h"

t_lst	*get_no_empty_elem_list(
		int fd,
		char const sep,
		t_bool (*is_empty)(char const*))
{
	t_fifo	*elems;
	char	*elem;

	elems = f_fifo_create();
	if (elems != NULL)
	{
		while (get_next_elem(fd, &elem, sep) == ONE_LINE_READ)
		{
			if (is_empty(elem))
				ft_strdel(&elem);
			else
			{
				if (f_fifo_add(elems, elem) == NULL)
				{
					f_fifo_destroy(&elems, ft_gen_strdel);
					ft_strdel(&elem);
					break ;
				}
			}
		}
	}
	return (f_fifo_extract(&elems));
}
