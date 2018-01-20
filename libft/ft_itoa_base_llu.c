/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_llu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:12:17 by bjanik            #+#    #+#             */
/*   Updated: 2017/04/03 20:07:34 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_digit(unsigned long long value, int size_base)
{
	int	digit;

	digit = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= size_base;
		digit++;
	}
	return (digit);
}

char		*ft_itoa_base_llu(unsigned long long value, char *base)
{
	char	*s;
	int		i;
	int		size_base;

	size_base = ft_strlen(base);
	i = nb_digit(value, size_base);
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
