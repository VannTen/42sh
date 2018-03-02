/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:28:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/12 17:39:03 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_defs.h"

char	f_to_unix_const(char c)
{
	if (c == '.')
		return ('_');
	else
		return (f_toupper(c));
}

char	f_toupper(char c)
{
	return (ft_toupper(c));
}

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	else
		return (c);
}
