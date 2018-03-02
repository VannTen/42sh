/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strsplit_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:14:05 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/27 15:18:39 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_interface.h"
#include "fifo_interface.h"
#include "string_interface.h"
#include "issomething_interface.h"
#include <stdlib.h>

/*
** The function proceeds with a loop performing the folowing actions :
** advance until the current character is different from the separator,
** while keeping an index to the previous separator (first being the beginning
** of the string).
** Then, send to new_split the adress of the first character of the current
** string split, and the size of the split (the current index minus the index of
** the previous separator).
** new_split then produces a lst link, which is put at the end of the list.
**
** TODO: (improvements)
** - Using a string as a delimiter, not a single character.
*/

static char		*new_split(char const *src, size_t size)
{
	size_t	index;
	char	*split;

	index = 0;
	split = malloc(sizeof(char) * (size + 1));
	if (split != NULL)
	{
		while (index < size)
		{
			split[index] = src[index];
			index++;
		}
		split[size] = '\0';
	}
	return (split);
}

t_lst			*f_strsplit_lst(char const *s, const char c)
{
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	return (f_strsplit_lst_mod(s, str, FALSE));
}

static size_t	get_begin(
		char const *str,
		char const *sep,
		t_bool const contiguous_sep_merge)
{
	size_t	index;

	index = 0;
	if (contiguous_sep_merge)
	{
		while (is_among(sep, str[index]) && str[index] != '\0')
			index++;
	}
	return (index);
}

static size_t	get_size(
		char const *str,
		char const *sep)
{
	size_t	index;

	index = 0;
	while (!is_among(sep, str[index]) && str[index] != '\0')
		index++;
	return (index);
}

t_lst			*f_strsplit_lst_mod(
		char const *str,
		char const *const sep,
		t_bool const contiguous_sep_merge)
{
	size_t	size;
	t_fifo	*strsplit;
	char	*split;

	strsplit = f_fifo_create();
	str += get_begin(str, sep, contiguous_sep_merge);
	while (TRUE)
	{
		size = get_size(str, sep);
		if (size != 0 || !contiguous_sep_merge)
		{
			split = new_split(str, size);
			if (NULL == f_fifo_add(strsplit, split))
			{
				f_fifo_destroy(&strsplit, ft_gen_strdel);
				break ;
			}
		}
		str += size;
		if (*str == '\0')
			break ;
		str++;
		str += get_begin(str, sep, contiguous_sep_merge);
	}
	return (f_fifo_extract(&strsplit));
}
