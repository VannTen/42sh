/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:05:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:10:47 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** Appends a copy of null-terminated s2 to null-terminated s2, writing over
** the null-terminating character of s1
** If the strings overlap, behavior is undefined
*/

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	while (s1[index1] != '\0')
		index1++;
	while (s2[index2] != '\0')
	{
		s1[index1] = s2[index2];
		index1++;
		index2++;
	}
	s1[index1] = '\0';
	return (s1);
}
