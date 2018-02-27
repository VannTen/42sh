/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:40:30 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:28:50 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** Compares two byte stings for up to n bytes
** return the diff between the first different bytes in the strings
** return zero if the strings are identical
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int			diff;
	size_t		index;
	const char	*mem1;
	const char	*mem2;

	index = 0;
	diff = 0;
	mem1 = (const char*)s1;
	mem2 = (const char*)s2;
	while (index < n
			&& (unsigned char)mem1[index] == (unsigned char)mem2[index])
		index++;
	if (index < n)
		diff = (int)((unsigned char)mem1[index] - (unsigned char)mem2[index]);
	return (diff);
}
