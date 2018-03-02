/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_array_cpy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:20:28 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/26 16:44:59 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char		**ft_str_array_cpy(char *const *src, char **dst)
{
	size_t	index;

	index = 0;
	while (src[index] != NULL)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = NULL;
	return (dst);
}
