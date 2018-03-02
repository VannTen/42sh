/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:24:39 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:29:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_interface.h"
#include <stddef.h>

/*
** Copy memory from source to dst
** The memory may overlap : if dst is smaller than src, there is no risk :
** src bytes can't be erased before being written.
** If dst is greater, the copy is made backwards, which reproduces the above
** situation.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		index;
	char		*mem_dst;
	const char	*mem_src;

	mem_dst = (char*)dst;
	mem_src = (const char*)src;
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		index = len;
		while (index > 0)
		{
			index--;
			mem_dst[index] = mem_src[index];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
