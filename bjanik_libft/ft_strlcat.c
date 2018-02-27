/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:09:02 by bjanik            #+#    #+#             */
/*   Updated: 2016/11/24 15:38:18 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	len_dst;
	int	i;
	int	max;

	len_dst = ft_strlen(dst);
	i = 0;
	max = size - 1;
	while (src[i] && ((len_dst + i) < max))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	if ((len_dst + i) > max)
		return (ft_strlen(src) + size);
	return (len_dst + ft_strlen(src));
}
