/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:22:58 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:22:02 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_defs.h"
#include <stddef.h>

/*
** Create an allocated copy with length of len from s[start].
** if start and len DO NOT designed a valid substring (meaning start + len
** go beyond the terminating NUL-character), behavior is undefined.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*strsub;
	size_t	index;
	size_t	index_start;

	if (s == NULL)
		return (NULL);
	strsub = ft_strnew(len);
	if (strsub != NULL)
	{
		index = 0;
		index_start = start;
		while (index < len)
		{
			strsub[index] = s[index_start];
			index++;
			index_start++;
		}
	}
	return (strsub);
}
