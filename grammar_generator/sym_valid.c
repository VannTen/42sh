/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:21:21 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/21 15:06:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_defs.h"
#include "libft.h"

t_bool	is_valid_sym_name_part(char const c)
{
	return (is_unix_constants(c) || ft_isdigit(c));
}

t_bool	is_valid_sym_name(char const *str)
{
	size_t	index;
	t_bool	empty;

	index = 0;
	empty = TRUE;
	while (str[index] != '\0'
			&& !is_valid_sym_name_part(str[index])
			&& is_among(" \t\n", str[index]))
		index++;
	while (str[index] != '\0' && is_valid_sym_name_part(str[index]))
	{
		index++;
		empty = FALSE;
	}
	if (empty)
		return (FALSE);
	while (str[index] != '\0'
			&& !is_valid_sym_name_part(str[index])
			&& is_among(" \t\n", str[index]))
		index++;
	return (str[index] == '\0');
}
