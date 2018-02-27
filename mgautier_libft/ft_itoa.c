/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:01:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:31:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_interface.h"
#include <stddef.h>

/*
** Positive and negative number are treated separately
** ft_digits give the size of the numbere of digits needed
** (0 is a special case, it would break the loop)
** The string is then allocated and filled
** (digits - 1 being the last digit position)
** ft_negative add one digit ('-')
*/

static size_t	ft_digits(int n)
{
	size_t digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

static char		*ft_positive(int n)
{
	char	*positive;
	size_t	digits;

	digits = ft_digits(n);
	positive = ft_strnew(digits);
	if (positive == NULL)
		return (positive);
	while (digits != 0)
	{
		digits--;
		positive[digits] = (n % 10) + '0';
		n = n / 10;
	}
	return (positive);
}

static char		*ft_negative(int n)
{
	char	*negative;
	size_t	digits;

	digits = ft_digits(n) + 1;
	negative = ft_strnew(digits);
	if (negative == NULL)
		return (negative);
	negative[0] = '-';
	while (n != 0)
	{
		digits--;
		negative[digits] = -(n % 10) + '0';
		n = n / 10;
	}
	return (negative);
}

char			*ft_itoa(int n)
{
	if (n < 0)
		return (ft_negative(n));
	else
		return (ft_positive(n));
}
