/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 17:54:41 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/13 13:06:12 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew_char(const size_t size, const char c)
{
	char	*str;
	size_t	index;

	index = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str != NULL)
	{
		while (index < size)
		{
			str[index] = c;
			index++;
		}
		str[index] = '\0';
	}
	return (str);
}
