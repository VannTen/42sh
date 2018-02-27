/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:12:49 by bjanik            #+#    #+#             */
/*   Updated: 2016/11/09 15:36:47 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (src == dest)
		return (dst);
	if (source < dest)
	{
		source += len - 1;
		dest += len - 1;
		while (len--)
			*dest-- = *source--;
	}
	else
	{
		while (len--)
			*dest++ = *source++;
	}
	return (dst);
}
