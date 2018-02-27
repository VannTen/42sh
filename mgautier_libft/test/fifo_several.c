/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_several.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:24:08 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/30 18:26:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo_interface.h"
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
	t_fifo		*list_1;
	t_fifo		*list_2;

	list_1 = str_to_fifo(str_1);
	list_2 = str_to_fifo(str_3);
	list_1 = join_fifo(list_1, str_to_fifo(str_2));
	RET_TEST(fifo_equ(list_1, list_2, test));
}
