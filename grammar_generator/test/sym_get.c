/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:47:55 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/21 17:41:49 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "prods_interface.h"
#include "test_interface.h"
#include "libft.h"
#include <stdlib.h>

static t_bool	test_left_recur(t_symbol **sym, t_prod **recur_prod)
{
	t_prod	*left_rec;
	t_bool	result;

	left_rec = take_left_recursive(sym[0]);
	result = prod_are_identical(left_rec, recur_prod[0])
		&& get_prod_nb(sym[0]) == 3;
	destroy_prod(&left_rec);
	return (result
			&& NULL == take_left_recursive(sym[1])
			&& NULL == take_left_recursive(sym[2]));
}

static t_bool	test_has_left_recur(t_symbol **syms)
{
	t_bool const	valid[] = {TRUE, FALSE, FALSE};
	size_t			index;

	index = 0;
	while (index < ARRAY_LENGTH(valid))
	{
		if (valid[index] != has_left_recursion(syms[index]))
			break ;
		index++;
	}
	return (!(index < ARRAY_LENGTH(valid)));
}

static t_bool	test_get_info(t_symbol **syms)
{
	return (ft_strequ(get_name(syms[0]), "SYMBOL")
			&& ft_strequ(get_name(syms[1]), "SYMBOL_2")
			&& ft_strequ(get_name(syms[2]), "SYMBOL_3"));
}

static t_bool	test(t_prod **prods, t_symbol **syms, ...)
{
	return (test_get_info(syms)
			&& test_has_left_recur(syms)
			&& test_left_recur(syms, prods));
}

int				main(void)
{
	const char	*str[] = {
		"SYMBOL HUI TRE",
		"SYMBOL_2 HUI TRE",
		"SYMBOL: UUUU JJJJ HH| WER| SYMBOL HUI TRE|FRE",
		"SYMBOL_2: UUUU SYMBOL_2 JJJJ HH| WER| SYMBOL HUI TRE|FRE",
		"SYMBOL_3: UUUU JJJ FF | JE SYMBOL_3 | K SYMBOL_3" };

	return (test_sym_prod(str, 2, 3, test) ? EXIT_SUCCESS : EXIT_FAILURE);
}
