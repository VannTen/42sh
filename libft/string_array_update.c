/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array_update.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:02:27 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/10 14:09:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool_interface.h"
#include "string_interface.h"
#include <stddef.h>

void	ft_strip_invalid(char **array, t_bool (*is_valid)(const char *))
{
	size_t	index;
	size_t	offset;

	index = 0;
	offset = 0;
	while (array[index + offset] != NULL)
	{
		if (!is_valid(array[index + offset]))
		{
			ft_strdel(&array[index]);
			offset++;
		}
		else
		{
			if (offset != 0)
			{
				array[index] = array[index + offset];
				array[index + offset] = NULL;
			}
			index++;
		}
	}
}
