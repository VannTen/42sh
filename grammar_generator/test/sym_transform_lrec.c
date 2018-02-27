/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_transform_lrec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:08:53 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/05 14:02:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include "prods_interface.h"
#include "test_interface.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static t_bool	test_inside(t_symbol const *sym, t_symbol const *sym1)
{
	char const	*str[] = {
		"SYM", "SYM_3", "SYM_LREC", "SYM_4", "SYM_LREC",
		"SYM_LREC", "SYM_4", "SYM_LREC", "HY", "SYM_LREC"
	};
	char const	*cmp[ARRAY_LENGTH(str)];
	size_t		index;

	cmp[0] = get_name(sym);
	cmp[1] = get_sym_name_n(get_prod_number(sym, 0), 0);
	cmp[2] = get_sym_name_n(get_prod_number(sym, 0), 1);
	cmp[3] = get_sym_name_n(get_prod_number(sym, 1), 0);
	cmp[4] = get_sym_name_n(get_prod_number(sym, 1), 1);
	cmp[5] = get_name(sym1);
	cmp[6] = get_sym_name_n(get_prod_number(sym1, 0), 0);
	cmp[7] = get_sym_name_n(get_prod_number(sym1, 0), 1);
	cmp[8] = get_sym_name_n(get_prod_number(sym1, 1), 0);
	cmp[9] = get_sym_name_n(get_prod_number(sym1, 1), 1);
	index = 0;
	while (index < ARRAY_LENGTH(str))
	{
		if (!ft_strequ(cmp[index], str[index]))
			break ;
		index++;
	}
	return (!(index < ARRAY_LENGTH(str)));
}

static t_bool	test_supp(t_symbol **syms, t_symbol const *sym_lrec)
{
	if (prods_are_equ(syms[0], syms[1])
			&& prods_are_equ(syms[2], sym_lrec))
		return (TRUE);
	else
	{
		print_sym_back(syms[0], STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		print_sym_back(syms[1], STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		print_sym_back(syms[2], STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		print_sym_back(sym_lrec, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		return (FALSE);
	}
}
	static t_bool	test_eliminate_left_recursion(
			__attribute__((unused))t_prod **prods,
			t_symbol **syms,
			...)
{
	t_symbol	*no_left_rec;
	t_bool		result;

	no_left_rec = eliminate_left_recursion(syms[0]);
	result = no_left_rec != NULL
		&& get_prod_nb(syms[0]) == 2 && get_prod_nb(no_left_rec) == 3
		&& ft_strequ(get_name(no_left_rec), "SYM_LREC")
		&& test_inside(syms[0], no_left_rec)
		&& test_supp(syms, no_left_rec);
	result = result && NULL == eliminate_left_recursion(syms[0]);
	result = result && NULL == eliminate_left_recursion(no_left_rec);
	destroy_symbol(&no_left_rec);
	return (result);
}

int				main(void)
{
	const char	*sym_str[] = {
		"SYM:SYM SYM_4 | SYM HY | SYM_3 | SYM_4",
		"NON_REC: SYM_3 SYM_LREC| SYM_4 SYM_LREC",
		"PROD:SYM_4 SYM_LREC | HY SYM_LREC | "
	};

	RET_TEST (test_sym_prod(
				sym_str,
				0,
				ARRAY_LENGTH(sym_str),
				test_eliminate_left_recursion));
}

/*
**		"SYM_2: SYM_3 SYM_LREC | SYM_4 SYM_LREC",
**		"SYM1_LREC: SYM_4 SYM_LREC | HY SYM_LREC|"};
*/
