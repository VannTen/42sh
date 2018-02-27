/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strljoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:38:47 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/25 12:09:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** f_strljoin
**
** Join two strings whose total lenght should be equal to size ;
** if that is not the case, f_strljoin will form a string of up to size
** characters, copying str_1, then str_2, until it reaches it's size limit.
** If ft_strlen(str_1) + ft_strlen(str_2) is bigger than size, then join is
** not terminated.
*/

char	*f_strljoin(const char *str_1, const char *str_2,
		const size_t size_1, const size_t size_2)
{
	char	*join;
	size_t	index_1;
	size_t	index_2;

	index_1 = 0;
	index_2 = 0;
	join = malloc(sizeof(char) * (size_1 + size_2 + 1));
	if (join != NULL)
	{
		while (index_1 < size_1)
		{
			join[index_1] = str_1[index_1];
			index_1++;
		}
		while (index_2 <= size_2)
		{
			join[index_2 + index_1] = *str_2;
			index_2++;
			str_2++;
		}
	}
	return (join);
}
