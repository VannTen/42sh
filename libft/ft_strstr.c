/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:26:45 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:21:36 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool_interface.h"
#include <stddef.h>

/*
** Locates the first occurence of little in big.
** Everytime the first character of the pattern is found,
** the comparaison is made ; if no diff is found, the position of the first
** character of the pattern in big is returned.
** If the pattern is not found, NULL is returned.
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

char			*ft_strstr(const char *big, const char *little)
{
	size_t	index;

	if (*little == '\0')
		return ((char*)big);
	index = 0;
	while (big[index] != '\0')
	{
		if (big[index] == *little)
			if (ft_compare(big + index, little))
				return ((char*)(big + index));
		index++;
	}
	return (NULL);
}
