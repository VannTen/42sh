/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:02:22 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/17 09:17:03 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include "sym_interface.h"
#include "libft.h"
#include "test_interface.h"
#include <stdlib.h>

static t_bool	test(t_prod **prods, t_symbol **syms, ...)
{
	size_t	index[2];

	index[0] = 0;
	while (index[0] < 3)
	{
		index[1] = 0;
		while (index[1] < 3)
		{
			if (!((is_left_recursive(prods[index[1]], syms[index[0]])
					&& index[1] == index[0])
					|| (index[1] != index[0]
					&& !is_left_recursive(prods[index[1]], syms[index[0]]))))
				return (FALSE);
			index[1]++;
		}
		index[0]++;
	}
	return (TRUE);
}

int main(void)
{
	char const	*str_prod[] = {
		"NON_TERM TERM_1 TERM_2",
		"TERM_1 TERM_2 NON_TERM",
		"TERM_2 NON_TERM TERM_1" ,"NON_TERM", "TERM_1", "TERM_2" };

	RET_TEST(test_sym_prod(str_prod, 3, 3, test));
}
