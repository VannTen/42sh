/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:26:45 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:18:21 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_defs.h"
#include "bool_interface.h"
#include <stddef.h>

/*
** Same as ft_strstr, except than big is searched for no more than
** len characters
** An additionnal check is performed whenever the first character of the pattern
** is found : if the lenght of the patter + the number of character already read
** is greater than len, the search is not performed.
** Testing this could be at the entrance of the first loop (which test
** the end of big), but the test would be performed for every character not just
** when matching occurs.
*/

static	t_bool	ft_compare(const char *search, const char *pattern)
{
	size_t	index;

	index = 0;
	while (pattern[index] != '\0')
	{
		if (pattern[index] != search[index])
			return (FALSE);
		index++;
	}
	return (TRUE);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	index;

	if (*little == '\0')
		return ((char*)big);
	little_len = ft_strlen(little);
	index = 0;
	while (big[index] != '\0')
	{
		if (big[index] == *little && (index + little_len <= len))
			if (ft_compare(big + index, little))
				return ((char*)(big + index));
		index++;
	}
	return (NULL);
}
