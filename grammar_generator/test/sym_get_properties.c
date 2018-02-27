/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_get_properties.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:17:56 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/03 18:20:42 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "test_interface.h"

static t_bool	test_has_empty(__attribute__((unused))t_prod **prods,
		t_symbol **syms, ...)
{
	return (!has_empty_prod(syms[0]) && has_empty_prod(syms[1]));
}

int	main(void)
{
	char const *sym[] = {"SYM_1: JJJJ EEEE LLLL | EEE | EEEEEE| JID",
		"SYM_2: JJJJ EEEE | | EEEEEELLLL"};

	RET_TEST(test_sym_prod(sym, 0, 2, test_has_empty));
}
