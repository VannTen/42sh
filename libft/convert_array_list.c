/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_array_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:30:47 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/18 17:03:13 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_data_struct_defs.h"
#include "lst_defs.h"
#include "fifo_defs.h"
#include "misc_interface.h"
#include "string_interface.h"
#include "bool_interface.h"
#include <stdlib.h>
#include <assert.h>

t_lst	*str_to_lst(char const *str)
{
	t_lst	*new_list;
	t_lst	*end;
	size_t	index;

	end = NULL;
	new_list = NULL;
	index = 0;
	while (str[index] != '\0')
	{
		if (NULL == f_add_end_lst_2(&end, str + index))
		{
			f_lstdel(&new_list, no_destroy);
			break ;
		}
		if (index == 0)
			new_list = end;
		index++;
	}
	return (new_list);
}

char	*lst_to_str(t_lst const *lst)
{
	char	*new_str;
	size_t	index;

	index = 0;
	new_str = ft_strnew(f_lst_len(lst));
	if (new_str != NULL)
	{
		while (lst != NULL)
		{
			new_str[index] = *(char*)lst->content;
			index++;
			lst = lst->next;
		}
	}
	return (new_str);
}

t_fifo	*str_to_fifo(char const *str)
{
	t_fifo	*fifo;

	assert(str != NULL);
	fifo = f_fifo_create();
	if (fifo != NULL)
	{
		fifo->begin_lst = str_to_lst(str);
		if (fifo->begin_lst == NULL)
			f_fifo_destroy(&fifo, no_destroy);
		else
			fifo->end_lst = lst_last_link(fifo->begin_lst);
	}
	return (fifo);
}

/*
** Take NULL-terminated array
*/

t_lst	*array_to_lst(void const *array_ptr)
{
	t_lst				*new_list;
	t_lst				*end;
	size_t				index;
	void const *const 	*array;

	end = NULL;
	new_list = NULL;
	index = 0;
	array = array_ptr;
	while (array[index] != NULL)
	{
		if (NULL == f_add_end_lst_2(&end, array[index]))
		{
			f_lstdel(&new_list, no_destroy);
			break ;
		}
		if (index == 0)
			new_list = end;
		index++;
	}
	return (new_list);
}

t_lst	*array_to_lst_index(void const *array_ptr, size_t size)
{
	t_lst				*new_list;
	t_lst				*end;
	size_t				index;
	void const *const 	*array;

	end = NULL;
	new_list = NULL;
	index = 0;
	array = array_ptr;
	while (index != size)
	{
		if (NULL == f_add_end_lst_2(&end, array[index]))
		{
			f_lstdel(&new_list, no_destroy);
			break ;
		}
		if (index == 0)
			new_list = end;
		index++;
	}
	return (new_list);
}
