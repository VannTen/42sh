/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvajoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 10:55:08 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:24:32 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_interface.h"
#include <stdarg.h>
#include <stdlib.h>

static char		**get_strings(size_t nb_string, va_list string_list)
{
	char	**string_array;
	size_t	index;

	index = 0;
	string_array = malloc(sizeof(char*) * (nb_string + 1));
	if (string_array != NULL)
	{
		while (index < nb_string)
		{
			string_array[index] = va_arg(string_list, char*);
			index++;
		}
		string_array[index] = NULL;
	}
	return (string_array);
}

static size_t	string_array_tot_length(char const*const*const string_array)
{
	size_t	index;
	size_t	tot_length;

	index = 0;
	tot_length = 0;
	while (string_array[index] != NULL)
	{
		tot_length += ft_strlen(string_array[index]);
		index++;
	}
	return (tot_length);
}

static size_t	sub_copy(const char *src, char *dst)
{
	size_t	index;

	index = 0;
	while (src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	return (index);
}

static char		*str_array_join(char const*const*const strings)
{
	size_t	index;
	size_t	total_length;
	size_t	final_index;
	char	*final_string;

	total_length = string_array_tot_length(strings);
	final_string = malloc(sizeof(char) * (total_length + 1));
	if (final_string != NULL)
	{
		final_index = 0;
		index = 0;
		while (strings[index] != NULL)
		{
			final_index += sub_copy(strings[index], final_string + final_index);
			index++;
		}
		final_string[final_index] = '\0';
	}
	return (final_string);
}

char			*ft_strvajoin(size_t nb_string, ...)
{
	va_list	string_list;
	char	**string_array;
	char	*final_string;

	va_start(string_list, nb_string);
	string_array = get_strings(nb_string, string_list);
	va_end(string_list);
	if (string_array != NULL)
		final_string = str_array_join((const char **)string_array);
	else
		final_string = NULL;
	free(string_array);
	return (final_string);
}
