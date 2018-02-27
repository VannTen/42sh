/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:53:28 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:29:46 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** Write n zeroed bytes to string s.
*/

void	ft_bzero(void *s, size_t n)
{
	size_t	index;
	char	*byte;

	index = 0;
	byte = (char*)s;
	while (index < n)
	{
		byte[index] = 0;
		index++;
	}
}
