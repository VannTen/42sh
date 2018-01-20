/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_umax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 14:59:50 by bjanik            #+#    #+#             */
/*   Updated: 2017/01/02 16:57:08 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_umax(uintmax_t value, char *base)
{
	char	*s;
	int		i;
	int		size_base;

	size_base = ft_strlen(base);
	i = ft_nb_digit_base(value, size_base);
	if ((s = (char*)malloc((i + 1) * sizeof(char))) == NULL)
		return (NULL);
	s[i--] = '\0';
	if (value == 0)
		s[i] = '0';
	while (value)
	{
		s[i--] = base[value % size_base];
		value /= size_base;
	}
	return (s);
}
