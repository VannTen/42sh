/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 12:35:57 by bjanik            #+#    #+#             */
/*   Updated: 2017/05/23 14:58:36 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew_set(int size, char c)
{
	char	*s;

	if (size < 1)
		return (NULL);
	if ((s = (char*)malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	s[size] = '\0';
	ft_memset(s, c, size);
	return (s);
}
