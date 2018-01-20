/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:03:41 by bjanik            #+#    #+#             */
/*   Updated: 2016/11/23 10:59:09 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return ((char*)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[j])
		{
			while ((big[i + j] == little[j]) && (little[j]) && (i + j) < len)
				j++;
			if (j == ft_strlen(little))
				return ((char*)&big[i]);
			else
			{
				j = 0;
				i++;
			}
		}
		else
			i++;
	}
	return (NULL);
}
