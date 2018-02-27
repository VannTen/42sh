/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_several.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:47:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/23 11:28:17 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_interface.h"
#include "convert_data_struct_interface.h"
#include <stdlib.h>

static t_bool	test(const void *a, const void *b)
{
	return (*(char*)a == *(char*)b);
}

int				main(void)
{
	const char	str_1[] = "ABC";
	const char	str_2[] = "DEF";
	const char	str_3[] = "ABCDEF";
	t_lst		*list_1;
	t_lst		*list_2;

	list_1 = str_to_lst(str_1);
	list_2 = str_to_lst(str_3);
	list_1 = join_lst(list_1, str_to_lst(str_2));
	return (lst_equ(list_1, list_2, test) ? EXIT_SUCCESS : EXIT_FAILURE);
}
