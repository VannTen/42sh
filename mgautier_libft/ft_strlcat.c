/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:39:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:14:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_defs.h"
#include <stddef.h>

/*
** size = buffer's size (counting NUL-terminating character)
** length = string's length (counting NUL-terminating character)
** Appends src at the end of dst, without going further than size
** If size characters are traversed in dst without finding a null,
** dst is assume to be size
** Return values (the length of the string that the function tried to create,
** meaning length of src + length of dst) takes that into account, so in that
** case, the function will return (size + strlen(src).
*/

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index_dst;
	size_t	index_src;
	size_t	length;
	size_t	length_2;

	if (size == 0)
		return (ft_strlen(src));
	index_dst = 0;
	index_src = 0;
	length = size - 1;
	while (index_dst < size && dst[index_dst] != '\0')
		index_dst++;
	if (dst[index_dst] != '\0')
		length_2 = size + ft_strlen(src);
	else
		length_2 = ft_strlen(dst) + ft_strlen(src);
	while (index_dst < length && src[index_src] != '\0')
	{
		dst[index_dst] = src[index_src];
		index_dst++;
		index_src++;
	}
	if (index_dst < size)
		dst[index_dst] = '\0';
	return (length_2);
}
