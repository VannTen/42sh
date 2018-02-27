/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:36:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:28:39 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** Locates the first occurence of c in s, and return a pointer to it.
** If no occurence is found in n bytes, NULL is returned
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	match;
	const char		*mem;

	index = 0;
	match = (unsigned char)c;
	mem = (const char*)s;
	while (index < n)
	{
		if ((unsigned char)mem[index] == match)
			return ((void*)(mem + index));
		index++;
	}
	return (NULL);
}
