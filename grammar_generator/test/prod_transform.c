/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:44:40 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/30 13:25:30 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include "sym_defs.h"
#include "test_interface.h"
#include "libft.h"
#include <unistd.h>

static t_bool	test_append_sym_to_left(
		t_prod **prods,
		__attribute__((unused))t_symbol **symbol,
		...)
{
	t_prod	*new_prod[2];
	t_bool	result;

	new_prod[0] = produce_developed_prod(prods[3], prods[0]);
	new_prod[1] = produce_developed_prod(prods[4], prods[0]);
	result = prod_are_equ(
			new_prod[0], prods[1])
		&& prod_are_equ(new_prod[1], prods[2]);
	if (!result)
	{
		print_prod_back(new_prod[0], STDERR_FILENO);
		print_prod_back(new_prod[1], STDERR_FILENO);
	}
	destroy_prod(&new_prod[0]);
	destroy_prod(&new_prod[1]);
	return (result);
}

int main(void)
{
	char const *str[] = {
		"SYM_2 SYM_1",
		"HY VU SYM_2 SYM_1",
		"TE TA SYM_2 SYM_1",
		"HY VU",
		"TE TA"
	};

	RET_TEST (test_sym_prod(str, 5, 0, test_append_sym_to_left));
}
