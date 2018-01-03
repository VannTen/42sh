/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:37:28 by bjanik            #+#    #+#             */
/*   Updated: 2016/11/09 11:08:20 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_bis;
	char	*src_bis;

	dst_bis = (char*)dst;
	src_bis = (char*)src;
	while (n--)
		*dst_bis++ = *src_bis++;
	return (dst);
}
