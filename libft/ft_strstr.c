/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:12:51 by bjanik            #+#    #+#             */
/*   Updated: 2016/11/07 15:13:51 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return ((char*)big);
	while (big[i])
	{
		if (big[i] == little[j])
		{
			while ((big[i + j] == little[j]) && (little[j]))
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
