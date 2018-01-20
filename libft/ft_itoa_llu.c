/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:34:38 by bjanik            #+#    #+#             */
/*   Updated: 2016/12/21 15:19:31 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_digit(unsigned long long n)
{
	int	digit;

	digit = 0;
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char		*ft_itoa_llu(unsigned long long n)
{
	char	*s;
	int		i;

	i = ft_nb_digit(n);
	if ((s = (char*)malloc((i + 1) * sizeof(char))) == NULL)
		return (NULL);
	s[i--] = '\0';
	if (n == 0)
		s[i] = 48;
	while (n)
	{
		s[i--] = n % 10 + 48;
		n /= 10;
	}
	return (s);
}
