/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:49:39 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/23 11:36:47 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_interface.h"
#include "string_array_interface.h"
#include <stdlib.h>

int	main(void)
{
	char const	src[] = "RReeR DDDDDwDiau Delwd    ides";
	char const	*expected_result[] = { "RReeR", "DDDDDDu",
		"Deld", "des", NULL };
	char		**test;
	int			result;

	test = ft_strsplit_and(src, ' ', ft_va_strstrip, "iwa");
	result = ft_str_arr_equ((char const *const *)expected_result,
				(char const *const *)test) ? EXIT_SUCCESS : EXIT_FAILURE;
	ft_free_string_array(&test);
	return (result);
}
