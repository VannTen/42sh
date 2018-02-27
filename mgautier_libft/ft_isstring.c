/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:46:00 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/23 16:56:13 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "issomething_defs.h"
#include "bool_interface.h"
#include <stddef.h>

t_bool	string_is_digit(const char *string)
{
	size_t	index;

	index = 0;
	while (ft_isdigit(string[index]))
		index++;
	return (string[index] == '\0');
}
