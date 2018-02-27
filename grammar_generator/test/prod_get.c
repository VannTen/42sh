/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:02:01 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/20 17:11:52 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include "test_interface.h"
#include <stdlib.h>

static t_bool	test_prod_get(
		t_prod **prods,
		__attribute__((unused))t_symbol **syms,
		...)
{
	if (get_prod_len(prods[1]) == 3)
		return (TRUE);
	return (FALSE);
}

/*
** TODO: Not sure if get_prod_len should deal with empty prod...
*/

int				main(void)
{
	char const *prods_str[] = {" ", "DEE JWWE UUU"};

	return (test_sym_prod(prods_str, 2, 0, test_prod_get) ?
			EXIT_SUCCESS : EXIT_FAILURE);
}
