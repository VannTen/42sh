/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:49:25 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 15:56:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Allocates memomy according to parameter, and initialize all bytes to 0;
*/

void	*ft_memalloc(size_t size)
{
	size_t	index;
	char	*memalloc;

	memalloc = (char*)malloc(size);
	index = 0;
	if (memalloc != NULL)
	{
		while (index < size)
		{
			memalloc[index] = 0;
			index++;
		}
	}
	return ((void*)memalloc);
}
