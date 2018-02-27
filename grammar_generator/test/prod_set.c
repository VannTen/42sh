/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 09:28:16 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/20 17:10:49 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include "test_interface.h"
#include "libft.h"
#include <stdlib.h>

static t_bool	test_prod_set(t_prod **prods, t_symbol **syms, ...)
{
	if (!(prefix_to_prod(prods[0], syms[0])
				&& prefix_to_prod(prods[0], syms[1])
				&& prod_are_identical(prods[0], prods[1])))
		return (FALSE);
	remove_symbols_head(prods[0], 2);
	if (!prod_are_identical(prods[0], prods[3]))
		return (FALSE);
	if (!(append_to_prod(prods[0], syms[0])
				&& append_to_prod(prods[0], syms[1])
				&& prod_are_identical(prods[0], prods[2])))
		return (FALSE);
	remove_symbols_tail(prods[0], 2);
	if (!prod_are_identical(prods[0], prods[3]))
		return (FALSE);
	return (TRUE);
}

int				main(void)
{
	char const	*prods_str[] = {
		"SYM_1 SYM_2 SYM_3 SYM_4",
		"SYM_6 SYM_5 SYM_1 SYM_2 SYM_3 SYM_4",
		"SYM_1 SYM_2 SYM_3 SYM_4 SYM_5 SYM_6",
		"SYM_1 SYM_2 SYM_3 SYM_4",
		"SYM_5", "SYM_6"};
	return (test_sym_prod(prods_str, 4, 2, test_prod_set) ?
			EXIT_SUCCESS : EXIT_FAILURE);
}
