/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:35:22 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/27 16:44:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_interface.h"
#include "issomething_interface.h"
#include "bool_interface.h"
#include <stdlib.h>

static t_bool	shall(char c)
{
	return (!is_among("\t ", c));
}
int	main(void)
{
	char const	*str[] = {
		" this is a string\t\t\t    dede h",
		"thisisastringdedeh" };
	char		*trip_str;
	t_bool		result;

	trip_str = ft_strdup(str[0]);
	ft_strip_in_place(trip_str, shall, TRUE);
	result = ft_strequ(str[1], trip_str);
	ft_strdel(&trip_str);
	return (result ? EXIT_SUCCESS : EXIT_FAILURE);
}
