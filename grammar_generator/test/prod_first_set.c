/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod_first_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:02:28 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/19 18:02:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prods_interface.h"
#include "libft.h"
#include "test_interface.h"

static char const	*g_str_symbol[] = {
	"A B C",
	"SYM SYM_B",
	"",
	"SYM SYM_1 SYM_C",
	"SYM: SYM_2 SYM_3 SYM_4|SYM_1 SYM_B",
	"SYM_1: A B C | D E F |",
	"SYM_B: G |"
};

static char const	*g_first_set[] = {
	"A",
	"SYM_2 A D G EMPTY",
	"EMPTY",
	"SYM_2 A D G SYM_C"
};

static t_bool		equ(void const *sym, void const *str_cmp)
{
	return (ft_strequ(get_name(sym), str_cmp));
}

static t_bool		check_prod_first_set(void const *prod,
		void const *str_first)
{
	t_lst	*first_set;
	t_lst	*first_set_cmp;
	t_bool	result;

	first_set = create_first_set_prod(prod);
	first_set_cmp = f_strsplit_lst(str_first, ' ');
	result = lst_equ(first_set, first_set_cmp, equ);
	f_lstdel(&first_set, no_destroy);
	f_lstdel(&first_set_cmp, ft_gen_strdel);
	return (result);
}

static t_bool		test_prod_first_set(t_prod **prod, t_symbol **sym, ...)
{
	(void)compute_first_sets(sym,
			ARRAY_LENGTH(g_str_symbol) - ARRAY_LENGTH(g_first_set));
	return (check_sets(
				prod, g_first_set, ARRAY_LENGTH(g_first_set),
				check_prod_first_set));
}

int	main(void)
{
	return (test_sym_prod(
				g_str_symbol,
				ARRAY_LENGTH(g_str_symbol)
				- (ARRAY_LENGTH(g_str_symbol) - ARRAY_LENGTH(g_first_set)),
				ARRAY_LENGTH(g_str_symbol) - ARRAY_LENGTH(g_first_set),
				test_prod_first_set));
}
