/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:03:02 by exam              #+#    #+#             */
/*   Updated: 2017/03/20 13:13:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_integer.h"
#include "itoa_tools.h"
#include "bool_interface.h"
#include <stdlib.h>
#include <stdint.h>

char	*ft_itoa_base(t_integer value, int base, const char *base_digits,
		t_bool is_signed)
{
	size_t	size;
	char	*itoa;

	if (base < 2)
		return (NULL);
	size = itoa_length(value, base, is_signed);
	itoa = (char*)malloc(sizeof(char) * (size + 1));
	itoa[size] = '\0';
	if (is_signed)
	{
		if (value.negative < 0)
			itoa_write_signed(itoa + size - 1, value.negative,
					base, base_digits);
		else
		{
			value.positive = value.negative;
			is_signed = FALSE;
		}
	}
	if (!is_signed)
		itoa_write_unsigned(itoa + size - 1, value.positive,
				base, base_digits);
	return (itoa);
}
