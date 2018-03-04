/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 11:32:31 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/04 15:28:44 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bleberr_macros.h"

int	str_to_fd(char const *str)
{
	char		has_max_len;
	size_t		len;
	size_t		i;

	if (str && (len = ft_strnlen(str, sizeof(INTMAX_STR))) < sizeof(INTMAX_STR))
	{
		has_max_len = (len == sizeof(INTMAX_STR) - 1);
		i = 0;
		while (str[i])
			if ('0' <= str[i] && str[i] <= (has_max_len ? INTMAX_STR[i] : '9'))
				i += 1;
			else
				return (-1);
		return (ft_atoi(str));
	}
	return (-1);
}
