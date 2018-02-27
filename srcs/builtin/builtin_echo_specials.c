/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo_specials.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:05:33 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/25 18:32:30 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		basetodeci_digit(char c, int base)
{
	const char	*ref;
	int			i;

	ref = "0123456789abcdef";
	i = 0;
	while (ref[i] && c != ref[i])
		++i;
	if (base < i)
		return (-1);
	else
		return (i);
}

static void		echo_conversion(char *str)
{
	char	c;
	int		ret;
	int		base;
	int		len;
	int		count;

	base = 8;
	len = 3;
	if (*str == 'x')
		base *= 2;
	else
		++len;
	count = 1;
	while (count < len && str[count] == ' ')
		++count;
	c = 0;
	while (count < len && (ret = basetodeci_digit(str[count], base)) != -1)
	{
		c = (c * 10) + ret;
		++count;
	}
	ft_strcpy(str + 1, str + count);
	*str = c;
	return ;
}

int				echo_specials(char *const start, int *const cancel_addr)
{
	char		*str;
	char		*ret;
	char const	ref[] = { 'a', 'b', 'c', 'e', 'f', 'n', 'r', 't', 'v', 47, 0 };
	char const	val[] = { 7, 8, 0, 29, 12, 10, 13, 9, 11, 47, 0 };

	str = start;
	while (*str != 0)
		if (*str == '\\' && *(++str) != 0)
			if ((ret = ft_strchr(ref, *str)) != NULL)
			{
				str[-1] = val[ret - ref];
				ft_memmove(str, str + 1, ft_strlen(str + 1) + 1);
				if (*ret == 'c')
				{
					*cancel_addr = 1;
					return (str - start - 1);
				}
			}
			else if (ft_strchr("0x", *str) != NULL)
				echo_conversion(str);
			else
				str += 1;
		else if (*str != 0)
			str += 1;
	return (str - start);
}
