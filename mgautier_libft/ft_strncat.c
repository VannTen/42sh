/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:05:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:16:15 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_defs.h"
#include <stddef.h>

/*
** Appends up to n characters from s2 to the end of s1, then add a terminating
** null character.
** If the two strings overlap, behavior is undefined.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	while (s1[index1] != '\0')
		index1++;
	while (index2 < n && s2[index2] != '\0')
	{
		s1[index1] = s2[index2];
		index1++;
		index2++;
	}
	s1[index1] = '\0';
	return (s1);
}
