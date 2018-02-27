/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:45:04 by bjanik            #+#    #+#             */
/*   Updated: 2017/01/13 17:22:29 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnstr(const char *str, int n)
{
	int	len;

	len = ft_strlen(str);
	if (n < len && n >= 0)
	{
		write(1, str, n);
		return (n);
	}
	else if (n > 0)
		write(1, str, len);
	return (len);
}
