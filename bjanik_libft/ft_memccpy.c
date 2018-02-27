/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:56:58 by bjanik            #+#    #+#             */
/*   Updated: 2016/12/09 11:05:17 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_bis;
	unsigned char	*src_bis;
	int				i;

	dst_bis = (unsigned char *)dst;
	src_bis = (unsigned char *)src;
	i = 0;
	while (n--)
	{
		dst_bis[i] = src_bis[i];
		i++;
		if (src_bis[i - 1] == (unsigned char)c)
			return ((dst_bis + i));
	}
	return (NULL);
}
