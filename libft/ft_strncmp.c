/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:09:22 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:16:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** Performs a comparaison between two strings, comparing up to n characters.
** Otherwise, behavior is the same than ft_strcmp
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		diff;
	size_t	cursor;

	diff = 0;
	cursor = 0;
	while ((cursor < n) && (diff == 0)
			&& (s1[cursor] != '\0' || s2[cursor] != '\0'))
	{
		diff = (unsigned char)s1[cursor] - (unsigned char)s2[cursor];
		cursor++;
	}
	return (diff);
}
