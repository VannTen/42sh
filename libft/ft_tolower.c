/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:33:12 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/09 17:03:16 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_defs.h"

char	f_tolower(char c)
{
	return (ft_tolower(c));
}

int		ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	else
		return (c);
}
