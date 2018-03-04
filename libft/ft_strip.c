/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 13:47:54 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/04 11:41:51 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_defs.h"
#include "issomething_interface.h"
#include <assert.h>

static char	*copy_new(char const *src, char const *to_strip, size_t index_dest)
{
	char	*dest;
	size_t	index;

	dest = ft_strnew(index_dest);
	if (dest != NULL)
	{
		index_dest = 0;
		index = 0;
		while (src[index] != '\0')
		{
			if (!is_among(to_strip, src[index]))
			{
				dest[index_dest] = src[index];
				index_dest++;
			}
			index++;
		}
	}
	return (dest);
}

char		*ft_strip(char const *src, char const *to_strip)
{
	size_t	index;
	size_t	index_dest;

	index = 0;
	index_dest = 0;
	while (src[index] != '\0')
	{
		if (!is_among(to_strip, src[index]))
			index_dest++;
		index++;
	}
	return (copy_new(src, to_strip, index_dest));
}

void		ft_strip_in_place(char *strip_from,
		t_bool (*shall)(char),
		t_bool keep)
{
	size_t	index;
	size_t	index_strip;

	index = 0;
	index_strip = 0;
	while (strip_from[index] != '\0')
	{
		if ((keep && shall(strip_from[index]))
				|| (!keep && !shall(strip_from[index])))
		{
			strip_from[index_strip] = strip_from[index];
			index_strip++;
		}
		else
			strip_from[index] = '\0';
		index++;
	}
	strip_from[index_strip] = '\0';
}

char		*ft_va_strstrip(char const *str, va_list args)
{
	return (ft_strip(str, va_arg(args, const char*)));
}
