/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:45:40 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/12 15:53:30 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_defs.h"
#include <stdlib.h>

/*
** Make an allocated copy of src and return it.
** If allocation fail, NULL is returned.
*/

char	*ft_strdup(const char *src)
{
	return (ft_strdup_to(src, '\0'));
}

char	*ft_strdup_to(const char *src, char const end)
{
	size_t	len;
	size_t	cursor;
	char	*dest;

	if (src == NULL)
		return (NULL);
	len = ft_strlen_gen(src, end);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (dest);
	cursor = 0;
	while (cursor < len + 1)
	{
		dest[cursor] = src[cursor];
		cursor++;
	}
	return (dest);
}

char	*ft_strndup(const char *src, size_t const size)
{
	return (ft_strndup_to(src, size, '\0'));
}

char	*ft_strndup_to(const char *src, size_t const size, char const end)
{
	size_t	len;
	size_t	cursor;
	char	*dest;

	len = ft_strnlen_gen(src, size, end);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (dest);
	cursor = 0;
	while (cursor < len)
	{
		dest[cursor] = src[cursor];
		cursor++;
	}
	dest[cursor] = '\0';
	return (dest);
}
