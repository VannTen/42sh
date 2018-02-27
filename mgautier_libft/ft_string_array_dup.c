/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_array_dup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 20:16:50 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/14 18:01:06 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_array_defs.h"
#include "string_interface.h"
#include <stdlib.h>
#include <stdarg.h>

static char	**content_copy(char const *const *src, char **dst, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		dst[index] = ft_strdup(src[index]);
		if (dst[index] == NULL)
		{
			ft_free_string_array(&dst);
			return (NULL);
		}
		index++;
	}
	dst[index] = NULL;
	return (dst);
}

char		**ft_string_array_dup(char const *const *string_array)
{
	char	**dup;
	size_t	size;

	if (string_array != NULL)
	{
		size = ft_string_array_count(string_array);
		dup = malloc(sizeof(char*) * (size + 1));
		if (dup != NULL)
			dup = content_copy(string_array, dup, size);
	}
	else
		dup = NULL;
	return (dup);
}

char		**ft_str_array_map_va(char const *const *str_array,
		char *(*map)(char const*, va_list), ...)
{
	va_list args;
	char	**result;

	va_start(args, map);
	result = ft_str_array_map_vas(str_array, map, args);
	va_end(args);
	return (result);
}

char		**ft_str_array_map_vas(char const *const *str_array,
		char *(*map)(char const*, va_list), va_list args)
{
	size_t	index;
	size_t	size;
	char	**array_map;
	va_list args_loc;

	size = ft_string_array_count(str_array);
	array_map = malloc(sizeof(char*) * (size + 1));
	if (array_map != NULL)
	{
		index = 0;
		while (index < size)
		{
			va_copy(args_loc, args);
			array_map[index] = map(str_array[index], args_loc);
			va_end(args_loc);
			if (array_map[index] == NULL)
			{
				ft_free_string_array(&array_map);
				return (NULL);
			}
			index++;
		}
		array_map[index] = NULL;
	}
	return (array_map);
}
