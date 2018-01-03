/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:56:28 by bjanik            #+#    #+#             */
/*   Updated: 2017/01/14 13:11:08 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_digit(unsigned long long n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char		*ft_itoa_u(unsigned long long n)
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
