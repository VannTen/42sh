/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:05:15 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/09 11:05:26 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool_interface.h"
#include <stddef.h>

t_bool		ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	else
		return (!0);
}

t_bool		is_among(char const *ref, int c)
{
	size_t	index;

	index = 0;
	while (c != ref[index] && ref[index] != '\0')
		index++;
	if (ref[index] != '\0')
		return (TRUE);
	else
		return (FALSE);
}

t_bool		is_unix_constants(int c)
{
	return ((c <= 'Z' && c >= 'A')
			|| c == '_');
}

t_bool		ft_isspace(int const c)
{
	return (is_among(" ", c));
}
