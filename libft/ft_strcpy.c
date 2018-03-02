/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:08:34 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:12:32 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** Copy the null-terminated string src into dst
** If src and dst overlap, behavior is undefined
*/

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	index;

	index = 0;
	while (src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
