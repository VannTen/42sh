/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 11:32:31 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/24 08:51:19 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bleberr_macros.h"

int	str_to_fd(char const *str)
{
	size_t	i;

	if (str)
	{
		i = 0;
		while (str[i])
			if (i < sizeof(INTMAX_STR)
					&& '0' <= str[i] && str[i] <= INTMAX_STR[i])
				i += 1;
			else
				return (-1);
		return (ft_atoi(str));
	}
	return (-1);
}
