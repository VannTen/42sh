/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:42:42 by bjanik            #+#    #+#             */
/*   Updated: 2017/01/09 15:10:59 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrdup(wchar_t *str)
{
	wchar_t	*s;

	if (str == NULL)
		return (NULL);
	if ((s = (wchar_t*)malloc(ft_wstrlen(str) + 1)) == NULL)
		return (NULL);
	while (*str)
	{
		*s = *str;
		str++;
		s++;
	}
	*s = '\0';
	return (s);
}
