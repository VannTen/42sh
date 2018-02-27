/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_char_of.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:31:34 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:25:04 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_interface.h"
#include <stddef.h>

char	last_char_of(const char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < 1)
		return ('\0');
	else
		return (str[len - 1]);
}
