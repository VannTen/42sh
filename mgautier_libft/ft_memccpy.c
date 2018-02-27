/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:18:16 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:28:26 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** Copy up to n bytes from dst to src
** If c occurs in src, copy stop after it and pointer to the next bytes in dst
** is returned
** Otherwise, copy n bytes and return NULL
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	check;
	size_t			index;
	char			*mem_dst;
	const char		*mem_src;

	index = 0;
	mem_dst = (char*)dst;
	mem_src = (const char*)src;
	check = (unsigned char)c;
	while (index < n)
	{
		mem_dst[index] = mem_src[index];
		index++;
		if ((unsigned char)mem_src[index - 1] == check)
			return ((void*)(mem_dst + index));
	}
	return (NULL);
}
