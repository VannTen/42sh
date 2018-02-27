/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:09:22 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:12:01 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** Compares two null-terminated string
** The first difference found is returned
** (numeric difference between unsigned char values)
** if no difference is found, zero is returned
*/

int	ft_strcmp(char const *s1, char const *s2)
{
	size_t	cursor;

	cursor = 0;
	while (s1[cursor] == s2[cursor] && s1[cursor] != '\0')
		cursor++;
	return (s1[cursor] - s2[cursor]);
}
