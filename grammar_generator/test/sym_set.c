/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:04:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/21 17:11:53 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "prods_interface.h"
#include "test_interface.h"
#include "libft.h"
#include <stdlib.h>

static t_bool	test_add_prod(t_prod **prod, t_symbol **syms, ...)
{
	t_bool	result;

	result = get_prod_nb(syms[0]) == 3
		&& get_prod_nb(syms[1]) == 2
		&& get_prod_nb(syms[2]) == 0;
	if (result)
	{
		add_prod(syms[2], dup_prod(prod[2]));
		add_prod(syms[2], dup_prod(prod[1]));
		result = get_prod_nb(syms[2]) == 2;
	}
	return (result);
}


int				main(void)
{
	const char	*symbol[] = {
		"SYMI OTHER SYMO",
		"OTHER_SYMBP OTHER",
		"SYM",
		"SYMBOL_1 : OTHER_SYMBP OTHER | SYM | SYMI OTHER SYMO",
		"SYMBOL_2 : OTHER_SYMBP OTHER | SYM ",
		"SYMBOL:" };

	return (test_sym_prod(symbol, 3, 3, test_add_prod) ?
			EXIT_SUCCESS : EXIT_FAILURE);
}
