/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:31:08 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:31:08 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_interface.h"
#include "string_interface.h"
#include "issomething_interface.h"
#include "stdout_interface.h"
#include <stdlib.h>

/*
** Recursion is used to go down until the end of the string
** From there, we're going back up with the 10-power
** (last digit is 10 ** 0 >> 1, previous 10 ** 1, and so on)
** Note : easily adaptable for any base with one more variable
**
** Line 51 is designed to mimic the behavior of atoi : if NULL is sent,
** a segfault happens.
*/

static int	ft_negative(const char *str, int *n)
{
	int	ten_power;

	if (*str < '0' || *str > '9')
		return (1);
	ten_power = ft_negative(str + 1, n);
	*n = *n - ((*str - '0') * ten_power);
	return (ten_power * 10);
}

static int	ft_positive(const char *str, int *n)
{
	int	ten_power;

	if (*str < '0' || *str > '9')
		return (1);
	ten_power = ft_positive(str + 1, n);
	*n = *n + ((*str - '0') * ten_power);
	return (ten_power * 10);
}

int			ft_atoi(const char *str)
{
	char	*digits;
	int		number;

	if (str == NULL)
		ft_putchar(str[0]);
	digits = ft_strtrim(str);
	if (digits == NULL)
		return (0);
	number = ft_strict_atoi(digits);
	free(digits);
	digits = NULL;
	return (number);
}

int			ft_strict_atoi(const char *str)
{
	size_t	size;
	int		number;

	size = 0;
	if (str[size] == '-' || str[size] == '+')
		size++;
	while (ft_isdigit(str[size]))
		size++;
	number = 0;
	if (*str == '-')
		ft_negative(str + 1, &number);
	else if (*str == '+')
		ft_positive(str + 1, &number);
	else
		ft_positive(str, &number);
	return (number);
}
