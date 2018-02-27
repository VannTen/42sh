/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstarray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:10:01 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/31 15:06:05 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include "bool_interface.h"
#include <stdlib.h>

size_t	f_lstarray_end_early(void *array, t_lst *lst, size_t size,
		t_bool (*put_lst_on_array)(const void *lst_content, void *array))
{
	size_t	count;

	count = size;
	while (count != 0 && lst != NULL)
	{
		if (put_lst_on_array(lst->content, array))
			count--;
		lst = lst->next;
	}
	return (count);
}

void	f_lstiterarray(void *array, t_lst *lst,
		void (*apply)(void *lst_content, void *array))
{
	while (lst != NULL)
	{
		apply(lst->content, array);
		lst = lst->next;
	}
}

void	f_lstmaparray(const void *src, void *dst, t_lst *list,
		t_bool (*advance_arrays)(const void **src, void **dst, void *modifier))
{
	while (advance_arrays(&src, &dst, list == NULL ? NULL : list->content))
		list = list->next;
}
