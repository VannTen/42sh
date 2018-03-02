/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 11:16:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/23 11:33:04 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_array_defs.h"
#include "string_interface.h"
#include "bool_interface.h"
#include <stddef.h>

size_t		ft_string_array_count(char const *const *str_array)
{
	size_t	index;

	index = 0;
	while (str_array[index] != NULL)
		index++;
	return (index);
}

/*
** Array coming in this function are guaranted to have the same length
*/

static int	comp(char const *const *array_1, char const *const *array_2)
{
	int		result;
	size_t	index;

	result = 0;
	index = 0;
	while (result == 0
			&& array_1[index] != NULL)
	{
		result = ft_strcmp(array_1[index], array_2[index]);
		index++;
	}
	return (result);
}

int			ft_str_arraycmp(char const *const *array_1,
		char const *const *array_2)
{
	size_t	size_1;
	size_t	size_2;

	size_1 = ft_string_array_count(array_1);
	size_2 = ft_string_array_count(array_2);
	if (size_1 < size_2)
		return (-1);
	else if (size_2 < size_1)
		return (1);
	else
		return (comp(array_1, array_2));
}

t_bool		ft_str_arr_equ(char const *const *arr_1, char const *const *arr_2)
{
	return (ft_str_arraycmp(arr_1, arr_2) == 0);
}
