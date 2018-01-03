/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:21:12 by bjanik            #+#    #+#             */
/*   Updated: 2017/01/15 19:19:49 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	handle_mask1(unsigned int mask, unsigned int value)
{
	unsigned char	octet;
	unsigned char	octet1;
	unsigned char	octet2;

	octet1 = value & 63;
	octet2 = (value >> 6) & 31;
	octet = (mask >> 8) | octet2;
	write(1, &octet, 1);
	octet = (mask << 24) >> 24 | octet1;
	write(1, &octet, 1);
}

static void	handle_mask2(unsigned int mask, unsigned int value)
{
	unsigned char	octet;
	unsigned char	octet1;
	unsigned char	octet2;
	unsigned char	octet3;

	octet1 = value & 63;
	octet2 = (value >> 6) & 63;
	octet3 = ((value >> 12) << 28) >> 28;
	octet = (mask >> 16) | octet3;
	write(1, &octet, 1);
	octet = ((mask << 16) >> 24) | octet2;
	write(1, &octet, 1);
	octet = ((mask << 24) >> 24) | octet1;
	write(1, &octet, 1);
}

static void	handle_mask3(unsigned int mask, unsigned int value)
{
	unsigned char	octet;
	unsigned char	octet1;
	unsigned char	octet2;
	unsigned char	octet3;
	unsigned char	octet4;

	octet1 = value & 63;
	octet2 = (value >> 6) & 63;
	octet3 = (value >> 12) & 63;
	octet4 = (value >> 18) & 7;
	octet = mask >> 24 | octet4;
	write(1, &octet, 1);
	octet = ((mask >> 16) & 255) | octet3;
	write(1, &octet, 1);
	octet = ((mask >> 8) & 255) | octet2;
	write(1, &octet, 1);
	octet = (mask & 255) | octet1;
	write(1, &octet, 1);
}

int			ft_putwchar_t(wchar_t c)
{
	unsigned int	mask1;
	unsigned int	mask2;
	unsigned int	mask3;
	int				len;

	mask1 = 49280;
	mask2 = 14712960;
	mask3 = 4034953344;
	len = ft_wchar_len(c);
	if (len == 1)
		write(1, &c, 1);
	else if (len == 2)
		handle_mask1(mask1, c);
	else if (len == 3)
		handle_mask2(mask2, c);
	else if (len == 4)
		handle_mask3(mask3, c);
	return (len);
}
